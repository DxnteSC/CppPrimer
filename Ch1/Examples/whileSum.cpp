#include <iostream>

int main()
{
    int sum = 0, val = 1;
    // keep executing the while loop whilst val is less than or equal to ten
    while (val <= 10)
    {
        sum += val; // assign sum + val to sum
        ++val; // increment val
    }
    std::cout << "The sum of the numbers from 1 to 10, inclusive is " << sum << std::endl;
    return 0;
}
