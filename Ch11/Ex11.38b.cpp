#include <fstream>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

std::unordered_map<std::string,std::string> buildMap(std::ifstream& map_file) {
    std::unordered_map<std::string,std::string> trans_map;
    std::string key, value;
    while (map_file >> key && getline(map_file,value)) {
        if (value.size() > 1) {
            trans_map[key] = value.substr(1);
        } else {
            throw std::runtime_error("No rule for: " + key);
        }
    }
    return trans_map;
}

const std::string& transform(const std::string& s, const std::unordered_map<std::string,std::string>& m) {
    auto map_it = m.find(s);
    if (map_it != m.end()) {
        return map_it->second;
    } else {
        return s;
    }
}

void word_transform(std::ifstream& map_file, std::ifstream& input) {
    auto transMap = buildMap(map_file);
    std::string text;
    while (getline(input,text)) {
        std::istringstream stream(text);
        std::string word;
        bool firstWord = true;
        while (stream >> word) {
            if (firstWord) {
                firstWord = false;
            } else {
                std::cout << " ";
            }
            std::cout << transform(word, transMap);
        }
        std::cout << std::endl;
    }
}

int main() {
    std::ifstream rules("transformRules");
    std::ifstream text("toBeTransformed");
    word_transform(rules,text);
}
