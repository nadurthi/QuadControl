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
    F[2]=20;
    F[1]=30;
    F[4]=200;
    F[4]=300;
    F.insert ( std::pair<int,int>(5,212) );
    F.insert ( std::pair<int,int>(4,213) );

    std::vector<int> V;
    V.push_back(1);
    V.push_back(2);
    V.push_back(3);

    //iterator over map
    for(auto const & pair : F){
        cout<<"map 1 F key = "<<pair.first<<" value = "<<pair.second<<endl;
    }

    for(std::map<int,int>::iterator it=F.begin();it!=F.end();it++){
        cout<<"map 2 F key = "<<it->first<<" value = "<<it->second<<endl;
    }

    // Iterator type 1 for vector
    for(auto value: V ){
    	cout<<"vector iterator = "<<value <<endl;
    }


    for(std::vector<int>::iterator it=V.begin(); it!=V.end(); it++ ){
    	cout<<"vector 2 iterator = "<<*it <<endl;
    }



    return 0;
}
