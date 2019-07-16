#include <iostream>
#include <vector>
#include <list>
#include <forward_list>

/*
 
vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
auto iter = vi.begin(); // call begin, not cbegin because we're changing vi
while (iter != vi.end()) {
 if (*iter % 2) {
    iter = vi.insert(iter, *iter);  // duplicate the current element
    iter += 2; // advance past this element and the one inserted before it
} else
    iter = vi.erase(iter);          // remove even elements
 // don't advance the iterator; iter denotes the element after the one we erased
}
*/

// code doesn't work for lists or forward_lists as they do not support iterator aritmetic operators. Also forward_lists don't support insert or erase.

int main() {
    
    std::list<int> l = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "List before edit: ";
    for (auto c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    for (std::list<int>::iterator i = l.begin(); i != l.end(); ++i) {
        if (*i % 2) {
            l.insert(i,*i);
        } else {
            l.erase(i);
        }
    }
    
    std::cout << "List after edit: ";
    for (auto c: l) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::forward_list<int> f = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Forward_List before edit: ";
    for (auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
    auto fBeforeBegin = f.before_begin();
    auto fBegin = f.begin();
    
    while (fBegin != f.end()) {
        if (*fBegin % 2) {
            fBegin = ++f.insert_after(fBegin, *fBegin);
            ++fBeforeBegin;
            ++fBeforeBegin;
        } else {
            fBegin =  f.erase_after(fBeforeBegin);
        }
    }
    
    std::cout << "Forward_List after edit: ";
    for (auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}

