#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int i, val = 5;
    while (std::cin >> i) {
        v.push_back(i);
    }
    auto valCount = std::count(v.cbegin(),v.cend(),val);
    std::cout << "The number of times " << val << " appears is " << valCount << std::endl;
}
