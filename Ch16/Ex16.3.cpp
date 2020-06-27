#include "Sales_data.h"
#include <iostream>

template <typename T> int compare(const T& t1, const T& t2)
{
    if (t1 < t2) return -1;
    else if (t2 < t1) return 1;
    else return 0;
}

int main()
{
    Sales_data a("a", 15, 10);
    Sales_data b("b",10,15);
    std::cout << compare(a,b) << std::endl;
}