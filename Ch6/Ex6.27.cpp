#include <iostream>

int sumInts(std::initializer_list<int> il) {
    int total = 0;
    for (const auto i: il) {
        total += i;
    }
    return total;
}

int main() {
    std::cout << sumInts({1,2,3,4,5}) << std::endl;
}
