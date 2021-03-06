#include"Sales_data.h"

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read (std::istream& is, Sales_data& data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

std::ostream &print (std::ostream& os, const Sales_data& data) {
    os << data.isbn() << " " << data.units_sold << " " << data.revenue;
    return os;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

Sales_data::Sales_data(std::istream& is) {
    read(is, *this);
}
