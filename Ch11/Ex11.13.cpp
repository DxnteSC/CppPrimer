#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<std::string,int>> pairs;
    std::string s;
    int i;
    while (std::cin >> s >> i) {
        pairs.push_back({s,i}); // easiest to write
        // pairs.push_back(std::make_pair(s,i));
        // pairs.push_back(std::pair<std::string, int>(s,i); easiest to understand
    }
    for (auto& c: pairs) {
        std::cout << "{" << c.first << ": " << c.second << "}" << std::endl;
    }
}
