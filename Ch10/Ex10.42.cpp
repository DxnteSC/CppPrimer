#include <iostream>
#include <list>
#include <string>

void elimDupes(std::list<std::string>& words) {
    std::cout << "Before Sort: ";
    for (const auto& i: words) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
    words.sort();
    std::cout << "After Sort: ";
    for (auto i: words) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
    words.unique();
    std::cout << "Uniquely Sorted, without duplicates: ";
    for (auto i: words) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
}

int main() {
    std::list<std::string> l = {"hi", "hello", "dante", "dante", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "the", "dante", "mage", "mage", "warlock", "mage", "hunter", "mage", "dante", "hi"};
    elimDupes(l);
}
