#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>

class Quote
{

public:
    Quote() = default;
    Quote(const std::string &s, double p) : bookNo(s), price(p) {}
    virtual ~Quote() = default;
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t) const;
    virtual void debug();

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug() override;

private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

class Limited_quote : public Quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
    void debug() override;

private:
    std::size_t max_qty = 0;
    double discount = 0.0;
};

void print_total(std::ostream &, const Quote &, std::size_t);

#endif