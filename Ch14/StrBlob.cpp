#include <stdexcept>

#include "StrBlob.h"

typedef std::vector<std::string>::size_type size_type;

void StrBlob::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::front()
{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

const std::string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    if (*lhs.data == *rhs.data)
        return true;
    return false;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return (*lhs.data < *rhs.data);
}

bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs < rhs);
}

std::string &StrBlob::operator[](std::size_t n)
{
    return (*data)[n];
}

const std::string &StrBlob::operator[](std::size_t n) const
{
    return (*data)[n];
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this, data->size());
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
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
    auto p = check(curr, "Deference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr()
{
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

std::string &StrBlobPtr::operator[](std::size_t n)
{
    return (*wptr.lock())[n];
}

const std::string &StrBlobPtr::operator[](std::size_t n) const
{
    return (*wptr.lock())[n];
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    --curr;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

StrBlobPtr &StrBlobPtr::operator+=(int n)
{ // uncheck range
    curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(int n)
{
    return *this += -n;
}

StrBlobPtr StrBlobPtr::operator+(int n) const
{
    StrBlobPtr ret = *this;
    return ret += n;
}

StrBlobPtr StrBlobPtr::operator-(int n) const
{
    StrBlobPtr ret = *this;
    return ret -= n;
}

int StrBlobPtr::operator-(const StrBlobPtr &rhs) const
{
    return curr - rhs.curr;
}

std::string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
std::string *StrBlobPtr::operator->() const
{
    return &this->operator*();
}

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
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
    auto p = check(curr, "Deference past end");
    return (*p)[curr];
}

ConstStrBlobPtr &ConstStrBlobPtr::incr()
{
    check(curr, "Increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

bool operator==(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

bool operator!=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return *lhs.wptr.lock() == *rhs.wptr.lock() && lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return rhs < lhs;
}

bool operator<=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const ConstStrBlobPtr &lhs, const ConstStrBlobPtr &rhs)
{
    return !(lhs < rhs);
}

std::string &ConstStrBlobPtr::operator[](std::size_t n)
{
    return (*wptr.lock())[n];
}

const std::string &ConstStrBlobPtr::operator[](std::size_t n) const
{
    return (*wptr.lock())[n];
}

const std::string &ConstStrBlobPtr::operator*() const
{
    auto p = check(curr, "deference past end");
    return (*p)[curr];
}
const std::string *ConstStrBlobPtr::operator->() const
{
    return &this->operator*();
}

StrBlobPtr *PtrToStrBlobPtr::operator->() const
{
    return ptr;
}