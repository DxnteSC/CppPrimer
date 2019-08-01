#include <iostream>
#include <list>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::list<int>> m = {{"hi", {1,32,89}}, {"yes",{2,4,6,8}}};
    for (auto& s: m) {
        std::cout << s.first << " occurs on pages ";
        for (auto c: s.second) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }
}
