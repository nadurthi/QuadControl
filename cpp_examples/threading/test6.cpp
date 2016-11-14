#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <boost/thread/condition_variable.hpp>

boost::condition_variable cond;
boost::mutex mut;
bool data_ready;
int data=0;
boost::shared_mutex _access;





void reader()
{
	for(int i=0;i<5;i++){
	  // get shared access
{
	std::cout<<"reader is waiting to start on "<< boost::this_thread::get_id() <<std::endl;
	  boost::shared_lock<boost::shared_mutex> lock(_access);
   		if (!lock.owns_lock())
      	  	{std::cout <<  ":******* Writer has the lock" << std::endl;}
    	else{
        	std::cout <<  ": Got the lock on " << boost::this_thread::get_id() <<std::endl;
			std::cout<<"reading on thread on "<<boost::this_thread::get_id()<<"\n";
	 		boost::this_thread::sleep_for(boost::chrono::seconds(3) );
			std::cout<<"Done reading on thread on "<<boost::this_thread::get_id()<<"\n";
			}
	 	
	 	boost::this_thread::sleep_for(boost::chrono::seconds(1) );
}
	  // now we have shared access

	}
}

void writer()
{
	    

	for(int i=0;i<3;i++){
 	 boost::this_thread::sleep_for(boost::chrono::seconds(2) );

  // get upgradable access
 	 {
std::cout<<"writing ... upgrade lock "<<i<<"\n";
  boost::upgrade_lock<boost::shared_mutex> lock(_access);

  // get exclusive access
	std::cout<<"writing ... upgrade to unique lock "<<i<<"\n";
  boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);
  // now we have exclusive access
		std::cout<<"------wrting on thread "<<boost::this_thread::get_id()<<"\n";
 	 boost::this_thread::sleep_for(boost::chrono::seconds(2) );
		std::cout<<"------Done writing on thread "<<boost::this_thread::get_id()<<"\n";
	}
}

}

int main() {

	boost::thread thread3(reader);
	// boost::thread thread4(reader);
	boost::thread thread5(writer);
	thread3.join();
	// thread4.join();
	thread5.join();



	return 1;
}