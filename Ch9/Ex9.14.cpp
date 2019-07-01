#include <iostream>
#include <string>
#include <vector>
#include <list>

int main() {
    std::list<char*> l = {"hello", "there", "how", "are", "you"};
    std::vector<std::string> v = {"i'm", "good", "thanks"};
    for (const auto& c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (const auto& c: v) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    v.assign(l.cbegin(),l.cend());
    for (const auto& c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (const auto& c: v) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
