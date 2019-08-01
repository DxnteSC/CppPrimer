#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<std::string,int>> pairs;
    std::string s;
    int i;
    while (std::cin >> s >> i) {
        pairs.push_back({s,i});
    }
    for (auto& c: pairs) {
        std::cout << "{" << c.first << ": " << c.second << "}" << std::endl;
    }
}
