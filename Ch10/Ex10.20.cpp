#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string make_plural(size_t ctr, const std::string& word,
                   const std::string& ending)
{
    return (ctr > 1) ? word + ending : word;
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
    stable_sort(words.begin(), words.end(),
                [](const std::string& a, const std::string& b)
                { return a.size() < b.size();});
    auto wc = find_if(words.begin(), words.end(), [sz](const std::string& a) { return a.size() >= sz; });
    auto count = count_if(words.begin(),words.end(),[sz] (const std::string& a) {return a.size() >= sz;});
    std::cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer" << std::endl;
    for_each(wc, words.end(), [](const std::string& s){std::cout << s << " ";});
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v = {"hi", "hello", "dante", "dante", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "the", "dante", "mage", "mage", "warlock", "mage", "hunter", "mage", "dante", "hi"};
    biggies(v, 6);
}
