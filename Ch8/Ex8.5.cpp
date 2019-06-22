#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void read(std::string& s, std::vector<std::string>& v) {
    std::ifstream input(s);
    std::string p;
    if (input) {
        while (input >> p) {
            v.push_back(p);
        }
    } else {
        std::cerr << "Error opening file: " << s << std::endl;
    }
}
        
int main() {
    std::string s = "input";
    std::vector<std::string> v_str;
    read(s,v_str);
    for (auto &c: v_str) {
        std::cout << c << std::endl;
    }
}
