#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> f = {0,1,2,3,4,5,6,7,8,9};
    std::forward_list<int>::iterator beforeCurr = f.before_begin();
    std::forward_list<int>::iterator curr = f.begin();
    std::cout << "Before Elements Removed: ";
    for(auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    while (curr != f.end()) {
        if (*curr % 2) {
            curr = f.erase_after(beforeCurr);
        } else {
            beforeCurr = curr;
            ++curr;
        }
    }
    std::cout << "After Elements Removed: ";
    for(auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
