#include <iostream>
#include <stdio.h>
#include <boost/format.hpp>  
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;  
using namespace boost;  
  
int main()  
{  
typedef boost::shared_ptr<int> CSamplePtr;

  // (A) create a container of CSample pointers:
  std::vector<CSamplePtr> vec;

  // (B) add three elements
  vec.push_back(CSamplePtr(new int));
  vec.push_back(CSamplePtr(new int));
  vec.push_back(CSamplePtr(new int));

  // (C) "keep" a pointer to the second: 
  CSamplePtr anElement = vec[1];

  // (D) destroy the vector:
  vec.clear();

  // (E) the second element still exists
  anElement.reset();
  printf("done. cleanup is automatic\n");

  // (F) anElement goes out of scope, deleting the last CSample instance

}  

