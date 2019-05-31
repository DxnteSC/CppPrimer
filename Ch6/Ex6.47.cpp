#include <iostream>
#include <vector>

void printVector(const std::vector<int>::const_iterator b, const std::vector<int>::const_iterator e) {
#ifndef NDEBUG
    std::cout << "Function called: " << __func__ << "in: " << __FILE__ << std::endl;
#endif
    if (b == e)
        return;
    std::cout << *b << std::endl;
    printVector(b + 1, e);
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5};
    printVector(v.begin(), v.end());
}
