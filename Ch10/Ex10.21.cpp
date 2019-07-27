#include <iostream>
#include <vector>

int main() {
    int i = 10;
    auto decrement = [&i] () -> bool {return i > 0 ? --i, false : true;};
    while (!decrement()) {
        std::cout << i << std::endl;
    }
    decrement();
    std::cout << "Zero Reached" << std::endl;
}
