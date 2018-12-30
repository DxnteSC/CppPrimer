#include <iostream>

int main()
{
    int sum =0, i = 0;
    std::cout << "Enter the numbers you want to sum:" << std::endl;
    while (std::cin >> i)
    {
        sum += i;
    }
    std::cout << "The sum of the values you entered was: " << sum << std::endl;
    return 0;
}
