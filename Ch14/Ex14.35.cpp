#include <iostream>
#include <string>
#include <vector>

class ReadInput
{
public:
    std::string operator()(std::istream &is) const
    {
        std::string s;
        if (std::getline(is, s))
        {
            return s;
        }
        else
        {
            return s;
        }
    }
};

int main()
{
    ReadInput r;
    std::vector<std::string> v;
    std::string s = r(std::cin);
    while (!s.empty())
    {
        v.push_back(s);
        s = r(std::cin);
    }

    for (const std::string &s : v)
    {
        std::cout << s << std::endl;
    }
}