#include <iostream>
#include <boost/thread.hpp>
#include <boost/thread/scoped_thread.hpp>
#include <boost/chrono.hpp>
#include <iostream>
#include <boost/thread/condition_variable.hpp>
 
class ThreadSafeCounter {
  private:
    boost::shared_mutex mutex_;
    int value_;

 public:
  ThreadSafeCounter(){
    value_=0;
  }
 
  // Multiple threads/readers can read the counter's value at the same time.
  int get() {
    boost::shared_lock<boost::shared_mutex> lock(mutex_);
    return value_;
  }
 
  // Only one thread/writer can increment/write the counter's value.
  void increment() {
    boost::unique_lock<boost::shared_mutex> lock(mutex_);
    value_++;
  }
 
  // Only one thread/writer can reset/write the counter's value.
  void reset() {
    boost::unique_lock<boost::shared_mutex> lock(mutex_);
    value_ = 0;
  }
 
 
};

ThreadSafeCounter counter;


void increment_and_print(){
for (int i = 0; i < 10; i++) {
      counter.increment();
      std::cout << boost::this_thread::get_id() << ' ' << counter.get() << '\n';
 
      // Note: Writing to std::cout actually needs to be synchronized as well
      // by another std::mutex. This has been omitted to keep the example small.
    }
} 
int main() {
 
 
  boost::thread thread1(increment_and_print);
  boost::thread thread2(increment_and_print);
  boost::thread thread3(increment_and_print);
  boost::thread thread4(increment_and_print);
 
  thread1.join();
  thread2.join();
  thread3.join();
  thread4.join();
}