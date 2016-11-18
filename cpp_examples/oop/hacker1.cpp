#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string ss;


    std::map<int,int> F;
    F[1]=2;
    F[2]=3;
    std::vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);

    // Iterator type 1 for vector
    for(auto value: V ){
    	cout<<"vector iterator = "<<value <<endl;
    }


    // for(auto const& value: V ){
    // 	cout<<"vector iterator = "<<value <<endl;
    // }

    return 0;
}
