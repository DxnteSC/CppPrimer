#include <iostream>
#include <vector>
#include <list>

int main() {
    
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    
    std::vector<int> v;
    std::list<int> l;
    for (int i = 0; i != 11; ++i) {
        v.push_back(ia[i]);
        l.push_back(ia[i]);
    }
    std::cout << "Vector: ";
    for(auto c: v) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << "List: ";
    for(auto c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    auto v_begin = v.begin();
    while (v_begin != v.end()) {
        if (*v_begin % 2 == 0) {
            v_begin = v.erase(v_begin);
        } else {
            ++v_begin;
        }
    }
    
    auto l_begin = l.begin();
    while (l_begin != l.end()) {
        if (*l_begin % 2 != 0) {
            l_begin = l.erase(l_begin);
        } else {
            ++l_begin;
        }
    }
    
    std::cout << "Vector: ";
    for(auto c: v) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << "List: ";
    for(auto c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

}
