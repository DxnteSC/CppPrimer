#include <iostream>

void swapInts(int &i, int &j) {
    int temp = i;
    i = j;
    j = temp;
}

int main() {
    int k = 19, l = 10393;
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
    swapInts(k,l);
    std::cout << "k: " << k << std::endl;
    std::cout << "l: " << l << std::endl;
}

//using references is way easier.
