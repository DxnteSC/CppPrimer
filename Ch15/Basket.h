#include "Quote.h"

#include <iostream>
#include <memory>
#include <set>

class Basket
{
public:
    //uses default constructor and copy-control members
    void add_item(const Quote &sale)
    {
        items.insert(std::shared_ptr<Quote>(sale.clone()));
    }
    void add_item(Quote &&sale)
    {
        items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
    }
    //prints total for each book, and the overall total for all items in the basket
    double total_receipt(std::ostream &) const;

private:
    // funstion to compare shared_ptr needed by multisrt
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
    {
        return lhs->isbn() < rhs->isbn();
    }
    // multiset to hold multiple quotes sorted by the compare member
    std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};