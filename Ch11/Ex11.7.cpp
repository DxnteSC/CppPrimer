#include <iostream>
#include <initializer_list>
#include <map>
#include <string>
#include <vector>

void addFamily(std::map<std::string,std::vector<std::string>>& m,const std::string& s, std::initializer_list<std::string> il = {}) {
    if (il.size() == 0) {
        std::vector<std::string> empty;
        m.insert({s,empty});
    } else {
        std::vector<std::string> sVec;
        for (auto& i : il) {
            sVec.push_back(i);
        }
        m.insert({s,sVec});
    }
}

void addKids(std::map<std::string,std::vector<std::string>>& m, const std::string& s, std::initializer_list<std::string> il = {}) {
    for (auto& str: il) {
        m[s].push_back(str);
    }
}

int main() {
    std::map<std::string, std::vector<std::string>> families;
    addFamily(families,"Detweiler", {"Digz", "TJ"});
    addFamily(families,"Long");
    addKids(families,"Long",{"Jake", "Haley"});
    for (auto c: families) {
        std::cout << c.first << std::endl;
        if ((c.second).empty() != true) {
            std::cout << "Kids: ";
            for (auto& s: c.second) {
                std::cout << s << " ";
            }
            std::cout << std::endl;
        }
    }
}
