#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    // Ex1.23
    Sales_data x;
    double xPrice = 0.0;
    int cnt = 0;
    if (std::cin >> x.bookNo >> x.units_sold >> xPrice)
    {
        cnt = 1;
        Sales_data y;
        double yPrice = 0.0;
        while (std::cin >> y.bookNo >> y.units_sold >> yPrice)
        {
            if (x.bookNo == y.bookNo)
            {
                ++cnt;
            }
            else
            {
                std::cout << "The total number of books sold for ISBN: " << x.bookNo << " was " << cnt << std::endl;
                x = y;
                cnt = 1;
            }
        }
        std::cout << "The total number of books sold for ISBN: " << x.bookNo << " was " << cnt << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "No Input" << std::endl;
        return 1;
    }
}
