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
    // Ex1.21
    Sales_data x, y;
    double xPrice = 0.0, yPrice = 0.0;
    std::cin >> x.bookNo >> x.units_sold >> xPrice >> y.bookNo >> y.units_sold >> yPrice;
    if (x.bookNo == y.bookNo)
    {
        x.revenue = x.units_sold * xPrice;
        y.revenue = y.units_sold * yPrice;
        int totalSold = x.units_sold + y.units_sold;
        double totalRevenue = x.revenue + y.revenue;
        double avg = totalRevenue / totalSold;
        std::cout << "Total No. of Books, ISBN: " << x.bookNo << ", sold was " << totalSold << " at a combined price of " << totalRevenue << ", therefore being sold on average at " << avg << " each." <<std::endl;
        return 0;
    }
    else
    {
        std::cout << "ISBN's do not match" << std::endl;
        return 1;
    }
}
