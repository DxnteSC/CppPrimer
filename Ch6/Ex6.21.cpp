#include <iostream>

int comp(const int &i, const int *ip) {
    if (i > *ip) {
        return i;
    } else if (*ip > i) {
        return *ip;
    } else {
        std::cout << "Values are equal" << std::endl;
        return 0;
    }
}

int main() {
    int i = 117, ij = 1117;
    int *j = &ij;
    std::cout << comp(i,j) << std::endl;
}
