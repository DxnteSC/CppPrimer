#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

class Sales_data
{
    friend std::istream &operator>>(std::istream &, Sales_data &);

    friend std::ostream &operator<<(std::ostream &, const Sales_data &);

    friend Sales_data operator+(const Sales_data &, const Sales_data &);

    friend std::istream &read(std::istream &, Sales_data &);

    friend std::ostream &print(std::ostream &, const Sales_data &);

    friend Sales_data add(const Sales_data &lhs, const Sales_data);

public:
    Sales_data() = default;
    Sales_data(const std::string &s) : bookNo(s) {}
    Sales_data(const std::string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(std::istream &);
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    Sales_data &operator+=(const Sales_data &);
    Sales_data &operator=(const std::string &);
    explicit operator double() const { return revenue; }
    explicit operator std::string() const { return bookNo; }

private:
    inline double avg_price() const
    {
        return units_sold ? revenue / units_sold : 0;
    }
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream &operator>>(std::istream &, Sales_data &);

std::ostream &operator<<(std::ostream &, const Sales_data &);

Sales_data operator+(const Sales_data &, const Sales_data &);

std::istream &read(std::istream &, Sales_data &);

std::ostream &print(std::ostream &, const Sales_data &);

Sales_data add(const Sales_data &lhs, const Sales_data &rhs);

#endif
