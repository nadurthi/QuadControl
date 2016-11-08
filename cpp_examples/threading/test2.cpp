#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>

void wait(int seconds)
{
  boost::this_thread::sleep_for(boost::chrono::seconds(seconds) );
}

void thread()
{
  for (int i = 0; i < 5; ++i)
  {
    wait(1);
    std::cout << i << '\n';
    std::cout <<"in test2"<<"\n";
    std::cout << boost::this_thread::get_id() << '\n';
  	std::cout << boost::thread::hardware_concurrency() << '\n';
  }
}

int main()
{
  boost::thread T(thread);
  boost::scoped_thread<> t(T);

}