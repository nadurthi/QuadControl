#include <iostream>  
#include <boost/format.hpp>  
#include <boost/shared_ptr.hpp>
#include <iostream>

using namespace std;  
using namespace boost;  
  
int main()  
{  
    unsigned int arr[5] = { 0x05, 0x04, 0xAA, 0x0F, 0x0D };  
  
    cout << format("%02X-%02X-%02X-%02X-%02X")  
            % arr[0]  
            % arr[1]  
            % arr[2]  
            % arr[3]  
            % arr[4]  
         << endl;  

    boost::shared_ptr<int> p1(new int(1));
    std::cout << *p1 << '\n';
    boost::shared_ptr<int> p2(p1);
    p1.reset(new int(2));
    std::cout << *p1.get() << '\n';
    p1.reset();
    std::cout << std::boolalpha << static_cast<bool>(p2) << '\n';
}  