#include <iostream>

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};

auto arrPtr(int i) -> int(&)[5] {
    return (i % 2) ? odd : even;
}

int main() {
    int i = 2;
    int j = 5;
    int (&arr1)[5] = arrPtr(i);
    int (&arr2)[5] = arrPtr(j);
    for (auto c: arr1) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    for (auto c: arr2) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
