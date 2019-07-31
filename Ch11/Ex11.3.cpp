#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::size_t> wordCount;
    std::string word;
    while (std::cin >> word) {
        ++wordCount[word];
    }
    for (const auto& w: wordCount) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;
    }
}
