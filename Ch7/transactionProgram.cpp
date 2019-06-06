#include "Sales_data.h"

int main() {
    
    Sales_data total;
    double price;
    if (read(std::cin,total)) {
        Sales_data trans;
        while (read(std::cin,trans)) {
            if (total.isbn() == trans.isbn()) {
                total.combine(trans);
            } else {
                print(std::cout, total) << std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    } else {
        std::cerr << "No Data" << std::endl;
        return -1;
    }
    return 0;
}
