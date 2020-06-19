#include "Quote.h"

int main()
{
    Quote q;
    std::cout << std::endl;
    Quote q1("q1", 34.5);
    std::cout << std::endl;
    Quote q2(q1);
    std::cout << std::endl;
    Quote q3 = q2;
    std::cout << std::endl;
    Bulk_quote bQ;
    std::cout << std::endl;
    Bulk_quote bQ1("bQ1", 45, 12, 40);
    std::cout << std::endl;
    Bulk_quote bQ2(bQ1);
    std::cout << std::endl;
    Bulk_quote bQ3 = bQ2;
    std::cout << std::endl;
    Bulk_quote bQ4("bQ4", 32, 5, 10);
    std::cout << std::endl;
    bQ4 = bQ3;
    std::cout << std::endl;
}