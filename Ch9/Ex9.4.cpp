#include <vector>
#include <iostream>

bool checkVal(std::vector<int>::iterator b, std::vector<int>::iterator e, int i) {
    std::vector<int>::iterator first, last;
    if (b == e) {
        if (i == (*b)) {
            return true;
        } else {
            return false;
        }
    } else if (b > e) {
        first = e;
        last = b;
    } else {
        first = b;
        last = e;
    }
    while (first != last) {
        if (i == (*first)) {
            return true;
        }
        ++first;
    }
    return false;
}

int main() {
    std::vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    if(checkVal(v.begin(),v.end(), 10) == true) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
    if(checkVal(v.begin(),v.end(), 3) == true) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" << std::endl;
    }
}
