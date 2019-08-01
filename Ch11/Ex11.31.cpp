#include <iostream>
#include <map>
#include <string>

void delWork(std::multimap<std::string,std::string>& m, const std::string& s) {
    auto check = m.find(s);
    if (check != m.end()) {
        m.erase(check);
    }
}

int main() {
    std::multimap<std::string,std::string> m = {{"George Orwell","Animal Farm"},{"Roald Dahl","Charlie and the Chocolate Factory"},{"George Orwell","1984"}, {"Roald Dahl", "The Twits"}};
    delWork(m,"George Orwell");
    for (auto& p: m) {
        std::cout << "{" << p.first << ", " << p.second << "}" << std::endl;
    }
}
