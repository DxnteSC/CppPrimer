#include <iostream>
#include <string>

struct Sales_data
{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg = 0.0;
};

int main()
{
    // Ex1.22
    Sales_data x;
    double xPrice = 0.0;
    if (std::cin >> x.bookNo >> x.units_sold >> xPrice)
    {
        Sales_data y;
        double yPrice;
        x.revenue = x.units_sold * xPrice;
        while (std::cin >> y.bookNo >> y.units_sold >> yPrice)
        {
            y.revenue = y.units_sold * yPrice;
            if (x.bookNo == y.bookNo)
            {
                x.units_sold += y.units_sold;
                x.revenue += y.revenue;
                x.avg = x.revenue / x.units_sold;
            }
        }
        std::cout << "ISBN: " << x.bookNo << " Units Sold: " << x.units_sold << " Total Revenue: " << x.revenue << " Avg Price: " << x.avg << std::endl;
    }
}
