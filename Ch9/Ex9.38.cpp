#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << "When empty" << std::endl;
    std::cout << "Size: " << v.size() << "; Capacity: " << v.capacity() << "." << std::endl;
    for (int i = 0; i != 25; ++i) {
        v.push_back(i);
    }
    std::cout << "After 25 elements are added:" << std::endl;
    std::cout << "Size: " << v.size() << "; Capacity: " << v.capacity() << "." << std::endl;
    v.reserve(50);
    std::cout << "After 50 bytes are reserved:" << std::endl;
    std::cout << "Size: " << v.size() << "; Capacity: " << v.capacity() << "." << std::endl;
    for (int i = 25; i != 100; ++i) {
        v.push_back(i);
    }
    std::cout << "After 75 more elements are added:" << std::endl;
    std::cout << "Size: " << v.size() << "; Capacity: " << v.capacity() << "." << std::endl;
    v.push_back(100);
    std::cout << "After 1 more elements is added to test capacity change:" << std::endl;
    std::cout << "Size: " << v.size() << "; Capacity: " << v.capacity() << "." << std::endl;
}
