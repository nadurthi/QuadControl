#include <boost/lockfree/queue.hpp>
#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <boost/atomic.hpp>
#include <iostream>

boost::lockfree::queue<int> q(100);
boost::atomic<int> sum;

void produce()
{
  for (int i = 1; i <= 1000; ++i)
    q.push(i);
}

void consume()
{
  int i=0;
  while (q.pop(i))
    std::cout <<boost::this_thread::get_id() <<" "<< i << '\n';
    sum += i;
}

int main()
{ 
  sum=0;
  boost::thread t1(produce);
  boost::thread t2(consume);
  boost::thread t3(consume);
  t1.join();
  t2.join();
  t3.join();
  consume();
  std::cout << sum << '\n';
}