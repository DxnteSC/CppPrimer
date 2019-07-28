#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
    std::vector<int> v ={0,0,1,1,1,2,3,4,4,5,5,5,5,5,6,6,6,7,7,8,9,9};
    std::list<int> l;
    std::unique_copy(v.begin(),v.end(),back_inserter(l));
    std::cout << "Unique copy: ";
    for (auto i: l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
