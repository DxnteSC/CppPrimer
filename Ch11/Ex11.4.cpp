#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    std::map<std::string, std::size_t> wordCount;
    std::set<std::string> excludes = {":",",","."};
    std::string word;
    while (std::cin >> word) {
        if (excludes.find(word) == excludes.end()) {
            std::transform(word.begin(),word.end(), word.begin(),[] (char c) {return std::tolower(c);});
            ++wordCount[word];
        }
    }
    for (const auto& w: wordCount) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;
    }
}

