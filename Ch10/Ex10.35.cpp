#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Vector: ";
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "Vector Reversed: ";
    for (auto it = v.end() - 1; it != v.begin() -1 ; --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
