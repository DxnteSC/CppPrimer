#include <iostream>
#include <string>
# include <list> // changed from #include <deque>

int main() {
    std::list<std::string> l; // changed from std::deque<std::string> d;
    std::string word;
    while (std::cin >> word) {
        l.push_back(word); //changed from d.push_back(word)
    }
    // changed from for (std::deque<std::string>::const_iterator i = d.cbegin(); i != d.cend(); ++i) {
    //    std::cout << *i << " ";
    //}
    for (std::list<std::string>::const_iterator i = l.cbegin(); i != l.cend(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}


