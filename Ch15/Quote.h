#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>
#include <string>
#include <utility>

class Quote
{
public:
    Quote()
    {
        std::cout << "Quote()" << std::endl;
    }
    Quote(const std::string &s, double p) : bookNo(s), price(p)
    {
        std::cout << "Quote(const std::string &s, double p)" << std::endl;
    }
    Quote(const Quote &);
    Quote &operator=(const Quote &);
    Quote(Quote &&) noexcept;
    Quote &operator=(Quote &&) noexcept;
    virtual ~Quote()
    {
        std::cout << "~Quote()" << std::endl;
    }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t) const;
    virtual void debug();

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &b, double p, std::size_t q, double d) : Quote(b, p), quantity(q), discount(d) {}
    double net_price(std::size_t) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote()
    {
        std::cout << "Bulk_quote()" << std::endl;
    }
    Bulk_quote(const std::string &b, double p, std::size_t min, double d) : Disc_quote(b, p, min, d)
    {
        std::cout << "Bulk_quote(const std::string &b, double p, std::size_t min, double d)" << std::endl;
    }
    Bulk_quote(const Bulk_quote &);
    Bulk_quote &operator=(const Bulk_quote &);
    Bulk_quote(Bulk_quote &&) noexcept;
    Bulk_quote &operator=(Bulk_quote &&) noexcept;
    double net_price(std::size_t) const override;
    void debug() override;
};

class Limited_quote : public Disc_quote
{
public:
    Limited_quote() = default;
    Limited_quote(const std::string &b, double p, std::size_t max, double d) : Disc_quote(b, p, max, d) {}
    double net_price(std::size_t) const override;
    void debug() override;
};

void print_total(std::ostream &, const Quote &, std::size_t);

#endif