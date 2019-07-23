#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> v;
    fill_n(back_inserter(v),5,0);
    for (const int i: v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}

