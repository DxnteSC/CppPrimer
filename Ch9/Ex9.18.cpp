#include <iostream>
#include <string>
#include <deque>

int main() {
    std::deque<std::string> d;
    std::string word;
    while (std::cin >> word) {
        d.push_back(word);
    }
    for (std::deque<std::string>::const_iterator i = d.cbegin(); i != d.cend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}


