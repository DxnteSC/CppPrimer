#include "Ex13.53.h"


bool HasPtr::operator< (const HasPtr& rhs) const
{
    return i < rhs.i;
}

void swap(HasPtr& lhs, HasPtr& rhs)
{
    std::cout << "External Swap" << std::endl;
    lhs.swap(rhs);
}