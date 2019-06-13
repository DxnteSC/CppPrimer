#include <string>
#include <iostream>

class Sales_data
{
friend std::istream &read (std::istream&, Sales_data&);
    
friend std::ostream &print (std::ostream&, const Sales_data&);
    
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {
        std::cout << "Constructor 1" << std::endl;
    }
    Sales_data() : Sales_data("",0,0) {
        std::cout << "Constructor 2" << std::endl;
    }
    Sales_data(const std::string& s) : Sales_data(s,0,0) {
        std::cout << "Constructor 3" << std::endl;
    }
    Sales_data(std::istream& is) : Sales_data() {
        read(is, *this);
        std::cout << "Constructor 4" << std::endl;
    };
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    inline double avg_price() const {
        return units_sold ? revenue/units_sold : 0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream &read (std::istream &is, Sales_data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

std::ostream &print (std::ostream &os, const Sales_data &data) {
    os << data.isbn() << " " << data.units_sold << " " << data.revenue;
    return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

int main() {
    Sales_data s1("AA",12,20);
    Sales_data s2;
    Sales_data s3("BB");
    Sales_data s4(std::cin);
}
