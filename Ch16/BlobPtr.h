#ifndef BLOB_PTR
#define BLOB_PTR

#include "Blob.h"

template <typename T>
bool operator==(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator!=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator<(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator>(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator<=(const BlobPtr<T> &, const BlobPtr<T> &);
template <typename T>
bool operator>=(const BlobPtr<T> &, const BlobPtr<T> &);

template <typename T>
class BlobPtr
{
public:
    friend bool operator==<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator!=<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator< <T>(const BlobPtr &, const BlobPtr &);
    friend bool operator><T>(const BlobPtr &, const BlobPtr &);
    friend bool operator<=<T>(const BlobPtr &, const BlobPtr &);
    friend bool operator>=<T>(const BlobPtr &, const BlobPtr &);

public:
    BlobPtr();
    explicit BlobPtr(Blob<T> &, std::size_t = 0);
    T &operator[](std::size_t);
    const T &operator[](std::size_t) const;
    BlobPtr &operator++();
    BlobPtr &operator--();
    BlobPtr operator++(int);
    BlobPtr operator--(int);
    T deref() const;
    BlobPtr &incr();
    BlobPtr &operator+=(int);
    BlobPtr &operator-=(int);
    BlobPtr operator+(int) const;
    BlobPtr operator-(int) const;
    int operator-(const BlobPtr &) const;
    T &operator*() const;
    T *operator->() const;

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T>::BlobPtr() : curr(0) {}

template <typename T>
BlobPtr<T>::BlobPtr(Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz) {}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
    {
        throw std::runtime_error("Unbound BlobPtr");
    }
    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }
    return ret;
}

template <typename T>
T BlobPtr<T>::deref() const
{
    auto p = check(curr, "Dereference past end of BlobPtr");
    return (*p)[curr];
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::incr()
{
    auto p = check(curr, "Increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

template <typename T>
bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator<=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs > rhs);
}

template <typename T>
bool operator>=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
T &BlobPtr<T>::operator[](std::size_t n)
{
    return (*wptr.lock())[n];
}

template <typename T>
const T &BlobPtr<T>::operator[](std::size_t n) const
{
    return (*wptr.lock())[n];
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++()
{
    check(curr, "Increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--()
{
    --curr;
    check(curr, "Decrement past begin of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    BlobPtr<T> ret = *this;
    ++*this;
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr<T> ret = *this;
    --*this;
    return ret;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator+=(int n)
{
    curr += n;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator-=(int n)
{
    return *this += -n;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator+(int n) const
{
    BlobPtr<T> ret = *this;
    return ret += n;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator-(int n) const
{
    BlobPtr<T> ret = *this;
    return ret -= n;
}

template <typename T>
int BlobPtr<T>::operator-(const BlobPtr<T> &rhs) const
{
    return curr - rhs.curr;
}

template <typename T>
T &BlobPtr<T>::operator*() const
{
    auto p = check(curr, "Dereference past end of BlobPtr");
    return (*p)[curr];
}

template <typename T>
T *BlobPtr<T>::operator->() const
{
    return &this->operator*();
}

#endif