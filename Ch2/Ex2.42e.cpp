#include "Sales_data.h"
#include <iostream>

int main()
{
    // Ex1.25
    Sales_data x;
    double xPrice = 0.0;
    if (std::cin >> x.bookNo >> x.units_sold >> xPrice)
    {
        x.revenue = x.units_sold * xPrice;
        Sales_data y;
        double yPrice;
        while (std::cin >> y.bookNo >> y.units_sold >> yPrice)
        {
            y.revenue = y.units_sold * yPrice;
            if (x.bookNo == y.bookNo)
            {
                x.units_sold += y.units_sold;
                x.revenue += y.revenue;
                x.avg = x.revenue/x.units_sold;
            }
            else
            {
                std::cout << "Total No. of Books, ISBN: " << x.bookNo << ", sold was " << x.units_sold << " at a combined price of " << x.revenue << " at an average of " << x.avg << std::endl;
                x = y;
            }
        }
        x.avg = x.revenue/x.units_sold;
        std::cout << "Total No. of Books, ISBN: " << x.bookNo << ", sold was " << x.units_sold << " at a combined price of " << x.revenue << " at an average of " << x.avg << std::endl;
    }
    return 0;
}
