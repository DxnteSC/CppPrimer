#include <iostream>
#include <vector>
#include <list>

int main() {
    // initialising a vector<double> from list<int>
    std::list<int> l = {0,1,2,3,4,5};
    std::vector<double> v(l.begin(),l.end());
    
    for(std::vector<double>::size_type i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    //initialising a vector<double> from vector<int>
    std::vector<int> v1 = {6,7,8,9,10};
    std::vector<double> v2(v1.begin(),v1.end());
    
    for(std::vector<double>::size_type i: v2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}
