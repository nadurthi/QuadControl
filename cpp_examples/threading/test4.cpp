#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <boost/thread/condition_variable.hpp>

boost::condition_variable_any cond;
boost::mutex mut;
bool data_ready;
int data=0;
boost::shared_mutex _access;



void reader()
{	

	while(1){
	if(data==-1){
		break;
	}

	{
	    // boost::unique_lock<boost::mutex> lock(mut);
	    boost::shared_lock<boost::shared_mutex> lock(_access);
		std::cout<<"unique lock after\n";

	    while((!data_ready && data!=-1))
	    {
			std::cout<<"waiting started on"<<boost::this_thread::get_id()<< "\n";
	        
	        cond.wait(lock);
			std::cout<<"waiting still"<<boost::this_thread::get_id()<< "\n";
			
	    }
	    data_ready=false;
		std::cout<<"------------processing data on "<<boost::this_thread::get_id()<< "\n";
		  boost::this_thread::sleep_for(boost::chrono::seconds(5) );
		std::cout<<"------------processed data = " <<data<<" :::: "<<boost::this_thread::get_id()<< "\n";
	}
}
		std::cout<<"****closing thread "<<boost::this_thread::get_id()<< "\n";

}



void writer()
{
	for(int i=1;i<=3;i++){

		std::cout<<"preparing\n";
		data=i;
		boost::this_thread::sleep_for(boost::chrono::seconds(2) );
		{
		std::cout<<"before lock gaurd\n";
		boost::lock_guard<boost::shared_mutex> lock(_access);
		std::cout<<"after lock gaurd\n";

		data_ready=true;
		std::cout<<"data ready\n";

		cond.notify_all();
		std::cout<<"notified\n";
		}
	}

	data=-1;
	data_ready=true;
    cond.notify_all();

	std::cout<<"****closing writer "<<boost::this_thread::get_id()<< "\n";



}

int main() {
	boost::thread thread1(reader);
	boost::thread thread2(reader);
	boost::thread thread3(writer);
	thread1.join();
	thread2.join();
	thread3.join();




	return 1;
}