#include <iostream>
#include <vector>

void printVector(const std::vector<int>::const_iterator b, const std::vector<int>::const_iterator e) {
    if (b == e)
        return;
    std::cout << *b << std::endl;
    printVector(b + 1, e);
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5};
    printVector(v.begin(), v.end());
    std::cout << std::endl;
    printVector(v.cbegin(), v.cend());
}
