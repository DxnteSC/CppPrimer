#include "HasPtr.h"

HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    std::string* temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
}
