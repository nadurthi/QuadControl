#include <iostream>
#include <stdio.h>
#include <boost/format.hpp>  
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;  
using namespace boost;  
  
int main()  
{  
    // (A) create a new CSample instance with one reference
    boost::shared_ptr<int> mySample(new int); 
    printf("The Sample now has %ld references\n", mySample.use_count()); // should be 1
    //
    //       // (B) assign a second pointer to it:
    boost::shared_ptr<int> mySample2 = mySample; // should be 2 refs by now
    printf("The Sample now has %ld references\n", mySample.use_count());
    //
    // (C) set the first pointer to NULL
    mySample.reset(); 
    printf("The Sample now has %ld references\n", mySample2.use_count());  // 1
    //
    // the object allocated in (1) is deleted automatically
    // when mySample2 goes out of scope
}  
