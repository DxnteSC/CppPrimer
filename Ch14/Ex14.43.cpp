#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v = {3, 4, 5, 6, 7, 8, 9};
    std::vector<int> divisors;
    std::cout << "Enter a number: " << std::endl;
    int i;
    std::cin >> i;
    std::modulus<int> mod;
    for (auto j : v)
    {
        if (!mod(i, j))
        {
            divisors.push_back(j);
        }
    }
    if (divisors.empty())
    {
        std::cout << "No divisors found in list" << std::endl;
    }
    else
    {
        std::cout << "The divisors are: {";
        for (int i : divisors)
        {
            std::cout << i << ", ";
        }
        std::cout << "}" << std::endl;
    }
}