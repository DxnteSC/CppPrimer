#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
    std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
    std::deque<int> d;
    std::list<int> l;
    std::vector<int> v;
    
    std::copy(vec.begin(),vec.end(),std::back_inserter(v)); // v = {1,2,3,4,5,6,7,8,9};
    std::copy(vec.begin(),vec.end(),std::front_inserter(d)); // d = {9,8,7,6,5,4,3,2,1};
    std::copy(vec.begin(),vec.end(), std::inserter(l,l.begin())); // l = {1,2,3,4,5,6,7,8,9};
    
    std::cout << "Original: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Back Inserter: ";
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Front Inserter: ";
    for (auto i: d) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Inserter: ";
    for (auto i: l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
