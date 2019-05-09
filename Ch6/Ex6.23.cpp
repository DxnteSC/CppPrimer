#include <iostream>

void print(const int i) {
    std::cout << "PRINT: " << i << std::endl;
}

void print1(const int *beg, const int *end) {
    std::cout << "PRINT 1: ";
    while (beg != end) {
        std::cout << *beg++ << " ";
    }
    std::cout << std::endl;
};

void print2(const int ia[], size_t size) {
    std::cout << "PRINT 2: ";
    for(size_t i = 0; i != size; ++i) {
        std::cout << ia[i] << " ";
    }
    std::cout << std::endl;
}

void print3(const int (&ia)[2]) {
    std::cout << "PRINT 3: ";
    for(auto i: ia) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    int i = 0, j[2] = {0,1};
    print(i);
    print1(std::begin(j), std::end(j));
    print2(j,2);
    print3(j);
}
