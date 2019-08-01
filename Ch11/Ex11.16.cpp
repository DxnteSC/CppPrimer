#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string,int> m = {{"A",1},{"B",2},{"C",3},{"D",4}};
    std::cout << "Before Edit:" << std::endl;
    for (const auto& p: m) {
        std::cout << "{" << p.first << ", " << p.second << "}" << std::endl;
    }
    auto it = m.begin();
    while (it != m.end()) {
        ++(it->second);
        ++it;
    }
    std::cout << "\nAfter Edit:" << std::endl;
    for (const auto& p: m) {
        std::cout << "{" << p.first << ", " << p.second << "}" << std::endl;
    }
}
