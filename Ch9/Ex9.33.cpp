#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    auto begin = v.begin();
    while (begin != v.end()) {
        (*begin)++;
        ++begin;
        begin = v.insert(begin, 0); // if we didn't assign begin to the value of insert, then begin becomes invalidated which leads to underfined behaviour.
        ++begin;
    }
    for (int i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
