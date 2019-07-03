#include <iostream>
#include <deque>
#include <list>

int main() {
    std::list<int> l = {0,1,2,3,4,5,6,7,8,9};
    std::deque<int> dEven;
    std::deque<int> dOdd;
    for (auto i = l.cbegin(); i != l.cend(); ++i) {
        if ((*i) % 2 == 0) {
            dEven.emplace_back(*i);
        } else {
            dOdd.emplace_back(*i);
        }
    }
    std::cout << "dEven: ";
    for (auto& c: dEven) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << "dOdd: ";
    for (auto& c: dOdd) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
