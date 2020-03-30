#include <iostream>
#include <string>

class StringLengthWithinBounds
{
public:
    StringLengthWithinBounds(std::size_t l, std::size_t u) : lowerBound(l), upperBound(u) {}
    bool operator()(const std::string &s)
    {
        return (s.length() >= lowerBound) && (s.length() <= upperBound);
    }

private:
    std::size_t lowerBound;
    std::size_t upperBound;
};

int main()
{
    StringLengthWithinBounds test(1, 10);
    std::string s;
    int count = 0;
    while (std::getline(std::cin, s))
    {
        if (test(s))
            ++count;
    }
    std::cout << "Number of words of size 1 through 10 (inclusive) is: " << count << std::endl;
}