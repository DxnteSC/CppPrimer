#include "Quote.h"

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

void Quote::debug()
{
    std::cout << "Quote: " << this->isbn() << " " << price << std::endl;
}

double Bulk_quote::net_price(std::size_t n) const
{
    if (n >= quantity)
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
    std::cout << "Bulk Quote: " << this->isbn() << " " << price << " " << quantity << " " << discount << std::endl;
}

double Limited_quote::net_price(std::size_t n) const
{
    if (n <= quantity)
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
    std::cout << "Limited Quote: " << this->isbn() << " " << price << " " << quantity << " " << discount << std::endl;
}

void print_total(std::ostream &os, const Quote &q, std::size_t n)
{
    double total = q.net_price(n);
    os << "Total price for ( " << q.isbn() << " ) is: " << total << std::endl;
}