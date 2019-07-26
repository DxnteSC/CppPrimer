#include <iostream>
#include <vector>

void addToVec (std::vector<int>& iVec, const int i) {
    auto sum = [i] (int j) {return i + j;};
    for (int& c: iVec) {
        c = sum(c);
    }
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Before function: ";
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    addToVec(v, 1);
    std::cout << "After function: ";
    for (auto i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
