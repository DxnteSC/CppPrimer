#include <iostream>
#include <initializer_list>
#include <map>
#include <string>
#include <utility>
#include <vector>

void addFamily(std::map<std::string,std::vector<std::pair<std::string,std::string>>>& m, const std::string& s, std::initializer_list<std::pair<std::string, std::string>> il = {}) {
    if (il.size() == 0) {
        std::vector<std::pair<std::string,std::string>> empty;
        m.insert({s,empty});
    } else {
        std::vector<std::pair<std::string,std::string>> sVec;
        for (auto& i: il) {
            sVec.push_back(i);
        }
        m.insert({s,sVec});
    }
}

void addKids(std::map<std::string,std::vector<std::pair<std::string,std::string>>>& m, const std::string& s, std::initializer_list<std::pair<std::string, std::string>> il = {}) {
    for (auto& p: il) {
        m[s].push_back(p);
    }
}

int main() {
    std::map<std::string,std::vector<std::pair<std::string,std::string>>> families;
    std::string familyName = "Long";
    addFamily(families,"Detweiler", {{"Digz","06/04/1994"}, {"TJ", "01/01/2001"}});
    addFamily(families,familyName);
    addKids(families,familyName,{{"Jake", "05/11/2003"},{"Haley","29/03/2005"}});
    std::cout << std::endl;
    for (auto c: families) {
        std::cout << "Family Name: " << c.first << std::endl;
        if ((c.second).empty() != true) {
            std::cout << "Kids: " << std::endl;
            for (auto& s: c.second) {
                std::cout << "Name: " << s.first << ", Birthday: " << s.second << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
