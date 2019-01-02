#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item1;
    int cnt = 0;
    if (std::cin >> item1)
    {
        cnt = 1;
        Sales_item item2;
        while (std::cin >> item2)
        {
            if (item1.isbn() == item2.isbn())
            {
                cnt++;
            }
            else
            {
                std::cout << "The total number of transactions which occurred for " << item1.isbn() << " was " << cnt << std::endl;
                item1 = item2;
                cnt = 1;
            }
        }
        std::cout << "The total number of transactions which occurred for " << item1.isbn() << " was " << cnt << std::endl;
    }
    else
    {
        std::cerr << "No input" << std::endl;
        return -1;
    }
    return 0;
}

