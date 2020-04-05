#include <iostream>

#include "Quote.h"

int main()
{
    Quote q = {"Boring", 5};
    Quote tQ = {"Not Boring", 7};
    Bulk_quote bQ1 = {"Also Not Boring", 7, 10, 0.10};
    Bulk_quote bQ2 = {"Also Not Boring - No Discount", 7, 10, 0.10};
    Limited_quote lQ1 = {"Also Also Not Boring - Discount", 7, 20, 0.10};
    Limited_quote lQ2 = {"Also Also Not Boring", 7, 20, 0.10};

    print_total(std::cout, q, 10);
    print_total(std::cout, tQ, 11);
    print_total(std::cout, bQ1, 11);
    print_total(std::cout, bQ2, 5);
    print_total(std::cout, lQ1, 15);
    print_total(std::cout, lQ2, 25);
}