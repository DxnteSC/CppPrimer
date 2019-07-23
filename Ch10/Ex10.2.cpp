#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main() {
    std::list<std::string> l;
    std::string s, val = "Dante";
    while (std::cin >> s) {
        l.push_back(s);
    }
    auto valCount = std::count(l.cbegin(),l.cend(),val);
    std::cout << "The number of times " << val << " appears is " << valCount << std::endl;
}
