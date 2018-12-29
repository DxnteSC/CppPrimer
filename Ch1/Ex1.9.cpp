// program to sum numbers from 50-100, inclusive
#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while (val <= 100)
    {
        sum += val;
        ++val;
    }
    std::cout << "The sum of the numbers from 50 to 100, inclusive is " << sum << std::endl;
    return 0;
}
