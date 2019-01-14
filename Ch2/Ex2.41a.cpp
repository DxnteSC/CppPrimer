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
    // Ex1.20
    Sales_data a;
    double price = 0.0;
    while (std::cin >> a.bookNo >> a.units_sold >> price)
    {
        a.revenue = a.units_sold * price;
        double avg = a.revenue / a.units_sold;
        std::cout << "ISBN: " << a.bookNo << " No. of Books Sold: " << a.units_sold << " Total Revenue: " << a.revenue << " Average Price: " << avg << std::endl;
    }
    return 0;
}
