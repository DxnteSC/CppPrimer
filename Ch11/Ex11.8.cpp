#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    std::map<std::string, std::size_t> word_count;
    std::vector<std::string> exclude = {"The", "But", "And", "Or", "An", "A",
        "the", "but", "and", "or", "an", "a"};
    std::string word;
    while (std::cin >> word) {
        if (std::find(exclude.begin(),exclude.end(),word) == exclude.end()) {
            ++word_count[word];
        }
    }
    for (auto& c: word_count) {
        std::cout << c.first << " occurs " << c.second << (c.second > 1 ? " times" : " time") << std::endl;
    } // Benefit of using set is that it is always ordered, if items are constantly being inserted and removed from the vector it may lead to performance issuesm, also algorithm doesn't need to be included when using set.
}
