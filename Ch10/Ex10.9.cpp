#include <algorithm>
#include <iostream>
#include <vector>

void elimDupes(std::vector<int>& vec) {
    std::cout << "Before Sort: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    sort(vec.begin(),vec.end());
    std::cout << "After Sort: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    auto endOfUnique = unique(vec.begin(),vec.end());
    std::cout << "Uniquely Sorted: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    vec.erase(endOfUnique,vec.end());
    std::cout << "Without Duplicates ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
}

int main() {
    std::vector<int> v = {5,5,0,1,2,4,2,5,0,6,4,3,6,7,5,5,9,9,8,6,0,3,3,7,8,8,3,5};
    elimDupes(v);
}
