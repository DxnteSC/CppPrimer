#include <iostream>

int main()
{
    int i = 5, j = 10;
    int *p = &i;
    std::cout << i << " " << j << " " << p << " " << *p << std::endl;
    *p = 7; // changes the value of the pointer
    std::cout << i << " " << j << " " << p << " " << *p << std::endl;
    p = &j; // changes the value to which the pointer points to
    std::cout << i << " " << j << " " << p << " " << *p << std::endl;
    return 0;
}
