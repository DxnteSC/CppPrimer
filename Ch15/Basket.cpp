#include "Basket.h"

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0; // holds running total
    //iter refers to the first element in a batch of elements with the same isbn
    // upper_bound returns an iterator to the element just past the end of that batch
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))
    {
        // we know there is atleast one element with this key in basket, print the line item for this book
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << "Total Sale: (" << sum << ")" << std::endl;
    return sum;
}