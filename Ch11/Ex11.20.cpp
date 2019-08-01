#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::size_t> wordCount;
    std::string word;
    while (std::cin >> word) {
        auto ret = wordCount.insert({word, 1});
        if (!ret.second) {
            ++ret.first->second;
            /*  ret holds the value returned by insert, which is a pair.
                ret.first is the first member of that pair, which is a map iterator referring to the element with the given key.
                ret.first-> dereferences that iterator to fetch that element. Elements in the map are also pairs.
                ret.first->second is the value part of the map element pair.
                ++ret.first->second increments that value.
             */
        }
    }
    for (const auto& w: wordCount) {
        std::cout << w.first << " occurs " << w.second << (w.second > 1 ? " times" : " time") << std::endl;
    }
    
    // Original program is easier to write and read as it is less code and avoids difficult to understand statements
}
