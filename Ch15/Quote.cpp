#include "Quote.h"

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

void Quote::debug()
{
    std::cout << "Quote: " << this->isbn() << " " << price << std::endl;
}

Bulk_quote::Bulk_quote(const std::string &s, double p, std::size_t min, double d) : Quote(s, p), min_qty(min), discount(d) {}

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= min_qty)
    {
        return n * price * (1 - discount);
    }
    else
    {
        return n * price;
    }
}

void Bulk_quote::debug()
{
    std::cout << "Bulk Quote: " << this->isbn() << " " << price << " " << min_qty << " " << discount << std::endl;
}

Limited_quote::Limited_quote(const std::string &s, double p, std::size_t max, double d) : Quote(s, p), max_qty(max), discount(d) {}

double Limited_quote::net_price(std::size_t n) const
{
    if (n <= max_qty)
    {
        return n * price * (1 - discount);
    }
    else
    {
        return n * price;
    }
}

void Limited_quote::debug()
{
    std::cout << "Limited Quote: " << this->isbn() << " " << price << " " << max_qty << " " << discount << std::endl;
}

void print_total(std::ostream &os, const Quote &q, std::size_t n)
{
    double total = q.net_price(n);
    os << "Total price for ( " << q.isbn() << " ) is: " << total << std::endl;
}