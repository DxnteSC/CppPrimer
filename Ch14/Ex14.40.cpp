#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDupes(std::vector<std::string> &vec)
{
    std::cout << "Before Sort: ";
    for (const auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << '\n'
              << std::endl;
    sort(vec.begin(), vec.end());
    std::cout << "After Sort: ";
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << '\n'
              << std::endl;
    auto endOfUnique = unique(vec.begin(), vec.end());
    std::cout << "Uniquely Sorted: ";
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << '\n'
              << std::endl;
    vec.erase(endOfUnique, vec.end());
    std::cout << "Without Duplicates ";
    for (auto i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << '\n'
              << std::endl;
}

class SmallerString
{
public:
    bool operator()(const std::string &a, const std::string &b) const
    {
        return a.size() < b.size();
    }
};

class SizeComp
{
public:
    SizeComp(std::vector<std::string>::size_type s) : sz(s) {}
    bool operator()(const std::string &str)
    {
        return str.size() < sz;
    }

private:
    std::vector<std::string>::size_type sz;
};

class Printer
{
public:
    void operator()(const std::string &s)
    {
        std::cout << s << " ";
    }
};

void biggies(std::vector<std::string> &sVec, std::vector<std::string>::size_type sz)
{
    elimDupes(sVec);
    stable_sort(sVec.begin(), sVec.end(), SmallerString());
    auto szStart = partition(sVec.begin(), sVec.end(), SizeComp(sz));
    std::cout << "Words with size greater than, or equal to " << sz << ": ";
    for_each(szStart, sVec.end(), Printer());
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> v = {"hi", "hello", "dante", "dante", "the", "worst", "best", "warrior", "mage", "hunter", "warlock", "paladin", "the", "dante", "mage", "mage", "warlock", "mage", "hunter", "mage", "dante", "hi"};
    biggies(v, 5);
}
