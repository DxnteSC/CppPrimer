#include "Quote.h"

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

void Quote::debug()
{
    std::cout << "Quote: " << this->isbn() << " " << price << std::endl;
}

Quote::Quote(const Quote &q)
{
    std::cout << "Quote(const Quote &q)" << std::endl;
    bookNo = q.bookNo;
    price = q.price;
}

Quote &Quote::operator=(const Quote &rhs)

{
    std::cout << "Quote::operator=(const Quote &rhs)" << std::endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote::Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
{
    std::cout << "Quote(Quote &&q))" << std::endl;
}

Quote &Quote::operator=(Quote &&rhs) noexcept
{
    std::cout << "Quote::operator=(Quote &&rhs)" << std::endl;
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
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

Bulk_quote::Bulk_quote(const Bulk_quote &bQ) : Disc_quote(bQ)
{
    std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
}
Bulk_quote &Bulk_quote::operator=(const Bulk_quote &rhs)
{
    std::cout << "Bulk_quote(const Bulk_quote &)" << std::endl;
    Disc_quote::operator=(rhs);
    return *this;
}

Bulk_quote::Bulk_quote(Bulk_quote &&bQ) noexcept : Disc_quote(std::move(bQ))
{
    std::cout << "Bulk_quote(Bulk_quote &&bQ)" << std::endl;
}
Bulk_quote &Bulk_quote::operator=(Bulk_quote &&rhs) noexcept
{
    std::cout << "Bulk_quote::operator=(Bulk_quote &&)" << std::endl;
    Disc_quote::operator=(std::move(rhs));
    return *this;
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