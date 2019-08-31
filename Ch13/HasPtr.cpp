#include "HasPtr.h"

ValueHasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    std::string* temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
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
