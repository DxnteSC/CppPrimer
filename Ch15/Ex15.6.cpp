#include <iostream>

#include "Quote.h"

int main()
{
    Quote q = {"Boring", 5};
    Quote tQ = {"Not Boring", 7};
    Bulk_quote bQ = {"Also Not Boring", 7, 10, 0.10};

    print_total(std::cout, q, 10);
    print_total(std::cout, tQ, 11);
    print_total(std::cout, bQ, 11);
}