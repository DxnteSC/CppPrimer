#include <string>
#include <iostream>

class Sales_data
{
friend std::istream &read (std::istream&, Sales_data&);
    
friend std::ostream &print (std::ostream&, const Sales_data&);
    
friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

public:
    Sales_data() = default;
    Sales_data(const std::string& s) : bookNo(s) {}
    Sales_data(const std::string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {}
    Sales_data(std::istream& is = std::cin) {read(is, *this);}

private:

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
