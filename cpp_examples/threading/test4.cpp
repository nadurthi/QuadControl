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



void wait_for_data_to_process()
{	

	while(1){
	if(data==-1){
		break;
	}


    boost::unique_lock<boost::mutex> lock(mut);
	std::cout<<"unique lock after\n";

    while(!data_ready)
    {
        cond.wait(lock);
	std::cout<<"waiting\n";

    }
    data_ready=false;
	std::cout<<"------------processing data\n";
	  boost::this_thread::sleep_for(boost::chrono::seconds(5) );
	std::cout<<"------------processed data = " <<data<<"\n";
}
}



void prepare_data_for_processing()
{
	for(int i=1;i<=3;i++){
	std::cout<<"preparing\n";
	data=i;
  boost::this_thread::sleep_for(boost::chrono::seconds(2) );
  		std::cout<<"before lock gaurd\n";
        boost::lock_guard<boost::mutex> lock(mut);
  		std::cout<<"after lock gaurd\n";
        
        data_ready=true;
		std::cout<<"data ready\n";
  
    cond.notify_one();
	std::cout<<"notified\n";
	}

	data=-1;
	data_ready=true;
    cond.notify_one();

}

void reader()
{
	for(int i=0;i<10;i++){
	  // get shared access

	  boost::shared_lock<boost::shared_mutex> lock(_access);
   		if (!lock.owns_lock())
      	  	{std::cout <<  ": Writer has the lock" << std::endl;}
    	else{
        	std::cout <<  ": Got the lock" << std::endl;
			std::cout<<"reading on thread "<<boost::this_thread::get_id()<<"\n";
	 		boost::this_thread::sleep_for(boost::chrono::seconds(3) );
			std::cout<<"Done reading on thread "<<boost::this_thread::get_id()<<"\n";
			}
	 	
	 	boost::this_thread::sleep_for(boost::chrono::seconds(1) );

	  // now we have shared access

	}
}

void writer()
{
	    

	for(int i=0;i<3;i++){

 	 boost::this_thread::sleep_for(boost::chrono::seconds(2) );

  // get upgradable access
  boost::upgrade_lock<boost::shared_mutex> lock(_access);

  // get exclusive access
  boost::upgrade_to_unique_lock<boost::shared_mutex> uniqueLock(lock);
  // now we have exclusive access
		std::cout<<"------wrting on thread "<<boost::this_thread::get_id()<<"\n";
 	 boost::this_thread::sleep_for(boost::chrono::seconds(2) );
		std::cout<<"------Done writing on thread "<<boost::this_thread::get_id()<<"\n";

}

}

int main() {
	std::cout<<"Initialize thread\n";
	boost::thread thread1(wait_for_data_to_process);
	boost::thread thread2(prepare_data_for_processing);
	std::cout<<"before thead1 join\n";
	thread1.join();
	std::cout<<"before thead2 join\n";
	thread2.join();
	std::cout<<"after join\n";

	boost::thread thread3(reader);
	boost::thread thread4(reader);
	boost::thread thread5(writer);
	thread3.join();
	thread4.join();
	thread5.join();



	return 1;
}