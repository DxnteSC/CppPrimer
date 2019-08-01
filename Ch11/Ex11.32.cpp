#include <iostream>
#include <map>
#include <set>
#include <string>


int main() {
    std::multimap<std::string,std::string> m = {{"George Orwell","Animal Farm"},{"Roald Dahl", "The Twits"},{"George Orwell","1984"}, {"Roald Dahl","Charlie and the Chocolate Factory"}};
    std::cout << "\nBefore Sort:" << std::endl;
    for (auto& p: m) {
        std::cout << "{" << p.first << ", " << p.second << "}" << std::endl;
    }
    std::cout << std::endl;
    std::map<std::string,std::multiset<std::string>> mOrdered;
    for (const auto& p: m) {
        mOrdered[p.first].insert(p.second);
    }
    std::cout << "After Sort:" << std::endl;
    for (auto& p: mOrdered) {
        std::cout << "Author: " << p.first << std::endl;
        for (auto s: p.second) {
            std::cout << s << std::endl;
        }
    }
    std::cout << std::endl;
}
