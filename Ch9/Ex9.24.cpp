#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int a = v[0]; // segmentation fault.
    int b = v.at(0); // terminates with std::out_of_range
    int c = v.front(); // segmentation fault
    int d = *(v.begin()); // segmentation fault
}
