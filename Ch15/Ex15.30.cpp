#include "Basket.h"
#include "Quote.h"

#include <memory>
#include <vector>

int main()
{
    Basket b;

    Bulk_quote q1("q1", 50, 10, 0.5);
    Bulk_quote q2("q2", 40, 8, 0.4);
    Bulk_quote q3("q3", 30, 6, 0.3);
    Bulk_quote q4("q4", 20, 4, 0.2);
    Bulk_quote q5("q5", 10, 2, 0.1);

    b.add_item(q1);
    b.add_item(q1);
    b.add_item(q1);
    b.add_item(q2);
    b.add_item(q3);
    b.add_item(q4);
    b.add_item(q5);

    b.total_receipt(std::cout);
}