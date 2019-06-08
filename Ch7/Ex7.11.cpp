#include "Sales_data.h"
#include <vector>

int main() {
    std::vector<Sales_data> v;
    Sales_data s1;
    Sales_data s2 = Sales_data("A");
    Sales_data s3 = Sales_data("B",5,10);
    Sales_data s4 = Sales_data(std::cin);
    v.push_back(s1);
    v.push_back(s2);
    v.push_back(s3);
    v.push_back(s4);
    
    
    for (auto c: v) {
        std::cout << c.bookNo << " " << c.units_sold << " " << c.revenue << std::endl;
    }
}
