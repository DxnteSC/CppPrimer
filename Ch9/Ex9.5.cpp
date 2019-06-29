#include <iostream>
#include <vector>

std::vector<int>::iterator getIndexIter(std::vector<int>::iterator b, std::vector<int>::iterator e, int i) {
    for (std::vector<int>::iterator iter = b; iter != e; ++iter) {
        if (i == (*iter)) {
            return iter;
        }
    }
    return e;
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    int i;
    std::cin >> i;
    std::vector<int>::iterator iter = getIndexIter(v.begin(),v.end(),i);
    if (iter == v.end()) {
        std::cerr << "Element not found" << std::endl;
    } else {
        std::cout << "Position of: " << *iter << " is " << iter - v.begin() << std::endl;
    }
}
