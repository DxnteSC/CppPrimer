#include <iostream>

int main() {
    auto sum = [] (const int i, const int j) {return i + j;};
    int a = 1, b = 7;
    std::cout << sum(4,5) << std::endl;
    std::cout << sum(a,b) << std::endl;
}
