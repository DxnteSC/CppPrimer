#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main() {
    std::string ascenders = "bdhklt", descenders = "gjpqy";
    std::string s;
    std::string words = "input";
    std::vector<std::string> v;
    std::ifstream input(words);
    if (input) {
        while (getline(input,s)) {
            v.push_back(s);
        }
    }
    for (auto i = v.begin(); i != v.end();) {
        if ((*i).find_first_of(ascenders) != std::string::npos || (*i).find_first_of(descenders) != std::string::npos ) {
            i = v.erase(i);
        } else {
            ++i;
        }
    }

    std::string biggest;
    if (v.size() == 1) {
        std::cout << "The longest word with neither an ascender or descender is: " << v[0] << std::endl;
    } else {
        for (auto i = v.begin();i != v.end() - 1; ++i) {
            if ((*i).size() < (*(i+1)).size()) {
                biggest = (*(i+1));
            } else {
                biggest = *i;
            }
        }
    std::cout << "The longest word with neither an ascender or descender is: " << biggest << std::endl;
    }
}
