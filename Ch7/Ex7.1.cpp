#include "Sales_data.h"

int main() {
    
    Sales_data total;
    double price;
    if (std::cin >> total.bookNo >> total.units_sold >> price) {
        total.revenue = total.units_sold * price;
        Sales_data trans;
        while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
            trans.revenue = trans.units_sold * price;
            if (trans.bookNo == total.bookNo) {
                total.units_sold += trans.units_sold;
                total.revenue += trans.revenue;
            } else {
                std::cout << "Sales for: " << total.bookNo << std::endl;
                std::cout << "Units sold: " << total.units_sold << std::endl;
                std::cout << "Total Revenue " << total.revenue << std::endl;
                total = trans;
            }
        }
        std::cout << "Sales for: " << total.bookNo << std::endl;
        std::cout << "Units sold: " << total.units_sold << std::endl;
        std::cout << "Total Revenue " << total.revenue << std::endl;
    } else {
        std::cerr << "No Data" << std::endl;
        return -1;
    }
    return 0;
}
