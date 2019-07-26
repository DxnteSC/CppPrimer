#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool longerThanFive(const std::string& s) {
    return (s.size() >= 5) ? true : false;
}

int main() {
    std::vector<std::string> v = {"hi", "hello", "dante", "gunslinger", "ranger", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "priest", "bard", "monk" };
    std::cout << "Before partition: ";
    for (auto c: v) {
        std::cout << c << " ";
    }
    std::cout << '\n' << std::endl;
    auto noLongerLongerThanFive = partition(v.begin(),v.end(),longerThanFive);
    std::cout << "After partition: ";
    for (auto c: v) {
        std::cout << c << " ";
    }
    std::cout << '\n' << std::endl;
    std::cout << "Words longer than or equal to five: ";
    for (auto i = v.begin(); i != noLongerLongerThanFive; ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}
