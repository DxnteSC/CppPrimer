#include <stdexcept>

#include "StrBlob.h"

typedef std::vector<std::string>::size_type size_type;

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data -> size()) {
        throw out_of_range(msg):
    }
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data -> pop_back();
}

std::string& StrBlob::front()
{
    check(0, "front on empty StrBlob");
    data -> front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    data -> back();
}

const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    data -> front();
}

const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    data -> back();
}
