#include <stdexcept>

#include "StrBlob.h"

typedef std::vector<std::string>::size_type size_type;

void StrBlob::check(size_type i, const std::string& msg) const
{
    if (i >= data -> size()) {
        throw std::out_of_range(msg);
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
    return data -> front();
}

std::string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data -> back();
}

const std::string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data -> front();
}

const std::string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data -> back();
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
    if (*lhs.data == *rhs.data)
        return true;
    return false;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
    return !(lhs == rhs);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("Unbound StrBlobPtr");
    }
    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }
    return ret;
}

std::string StrBlobPtr::deref() const
{
    auto p = check(curr,"Deference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
    return !(lhs == rhs);
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("Unbound StrBlobPtr");
    }
    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }
    return ret;
}

const std::string ConstStrBlobPtr::deref() const
{
    auto p = check(curr,"Deference past end");
    return (*p)[curr];
}

ConstStrBlobPtr& ConstStrBlobPtr::incr()
{
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
    return !(lhs == rhs);
}