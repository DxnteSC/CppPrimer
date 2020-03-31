#include <functional>
#include <iostream>
#include <map>
#include <string>

int minus(int i, int j)
{
    return i - j;
}

struct multiply
{
    int operator()(int i, int j) { return i * j; }
};

std::function<int(int, int)> mod = [](int i, int j) { return i % j; };

struct power
{
    int operator()(int i, int j)
    {
        int ans = 1;
        for (int count = 0; count != j; count++)
        {
            ans *= i;
        }
        return ans;
    }
};

int main()
{
    std::map<std::string, std::function<int(int, int)>> deskCalculator =
        {
            {"+", std::plus<int>()},
            {"-", minus},
            {"x", multiply()},
            {"/", [](int i, int j) { return i / j; }},
            {"%", mod},
            {"pow", power()},
        };
    std::cout << deskCalculator["+"](23, 6) << std::endl;
    std::cout << deskCalculator["-"](54, 6) << std::endl;
    std::cout << deskCalculator["x"](2, 4) << std::endl;
    std::cout << deskCalculator["/"](36, 9) << std::endl;
    std::cout << deskCalculator["%"](58, 2) << std::endl;
    std::cout << deskCalculator["pow"](6, 3) << std::endl;
}