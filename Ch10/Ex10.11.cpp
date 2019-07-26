#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDupes(std::vector<std::string>& vec) {
    std::cout << "Before Sort: ";
    for (const auto& i: vec) {
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

bool isShorter(const std::string& s1, const std::string& s2) {
    return s1.size() < s2.size();
}

int main() {
    std::vector<std::string> v = {"hi", "hello", "dante", "dante", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "the", "dante", "mage", "mage", "warlock", "mage", "hunter", "mage", "dante", "hi"};
    elimDupes(v);
    stable_sort(v.begin(),v.end(),isShorter);
    std::cout << "After stable sort: ";
    for (auto c:v) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    
}
