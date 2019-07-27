#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::string makePlural(size_t ctr, const std::string& word,
                   const std::string& ending) {
    return (ctr > 1) ? word + ending : word;
}

bool checkSizeLess (const std::string& s, std::string::size_type sz) {
    return s.size() <= sz;
}

bool checkSizeMore (const std::string& s, std::string::size_type sz) {
    return s.size() > sz;
}

bool isShorter (const std::string& a, const std::string& b) {
    return a.size() < b.size();
}

std::ostream& print(std::ostream& os, const std::string& s, char c) {
    os << s << c;
    return os;
}

void elimDupes(std::vector<std::string>& vec) {
    std::cout << "Before Sort: ";
    for (const auto& i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
    sort(vec.begin(),vec.end());
    std::cout << "After Sort: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
    auto endOfUnique = unique(vec.begin(),vec.end());
    std::cout << "Uniquely Sorted: ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
    vec.erase(endOfUnique,vec.end());
    std::cout << "Without Duplicates ";
    for (auto i: vec) {
        std::cout << i << " ";
    }
    std::cout << '\n' << std::endl;
}

void biggies(std::vector<std::string>& words,
             std::vector<std::string>::size_type sz)
{
    elimDupes(words);
    std::stable_sort(words.begin(), words.end(),isShorter);
    auto wc = std::find_if(words.begin(), words.end(),std::bind(checkSizeMore, std::placeholders::_1,sz));
    auto count = std::count_if(words.begin(),words.end(), std::bind(checkSizeLess, std::placeholders::_1,sz));
    std::cout << count << " " << makePlural(count, "word", "s") << " of length " << sz << " or less" << std::endl;
    std::for_each(words.begin(), wc, std::bind(print, std::ref(std::cout), std::placeholders::_1, ' '));
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v = {"hi", "hello", "dante", "dante", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "the", "dante", "mage", "mage", "warlock", "mage", "hunter", "mage", "dante", "hi"};
    biggies(v, 6);
}
