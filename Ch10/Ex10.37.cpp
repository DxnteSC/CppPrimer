#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main() {
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    std::list<int> l;
    auto begin = v.rbegin() + 3 ;
    auto end = v.rbegin() + 8;
    std::copy(begin,end,std::back_inserter(l));
    for (auto i: l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
