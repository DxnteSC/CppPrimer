#include <iostream>

#include "HasPtr.h"

int main()
{
    ValueHasPtr a("Dante", 5);
    ValueHasPtr b("Tosan", 10);
    std::cout << "Before Swap" << std::endl;
    std::cout << "a: " << a.GetString() << ", " << a.GetInt() << std::endl;
    std::cout << "b: " << b.GetString() << ", " << b.GetInt() << std::endl;
    swap(a,b);
    std::cout << "After Swap" << std::endl;
    std::cout << "a: " << a.GetString() << ", " << a.GetInt() << std::endl;
    std::cout << "b: " << b.GetString() << ", " << b.GetInt() << std::endl;
}
