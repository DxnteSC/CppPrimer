#include <iostream>

void reset(int &i) {
    i = 0;
}

int main() {
    int i;
    std::cout << "Enter a number" << std::endl;
    std::cin >> i;
    reset(i);
    std::cout << "Your number has been reset to: " << i << std::endl;
    return 0;
}
