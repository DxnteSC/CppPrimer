#include "HasPtr.h"

ValueHasPtr& ValueHasPtr::operator= (const ValueHasPtr& rhs)
{
    std::string* temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
}

bool ValueHasPtr::operator< (const ValueHasPtr& rhs) const
{
    return i < rhs.i;
}

void swap(ValueHasPtr& lhs, ValueHasPtr& rhs)
{
    std::cout << "External Swap" << std::endl;
    lhs.swap(rhs);
}

PointerHasPtr::~PointerHasPtr()
{
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
}

PointerHasPtr& PointerHasPtr::operator=(const PointerHasPtr& rhs)
{
    ++*rhs.use;
    if (--*use == 0)
    {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}
