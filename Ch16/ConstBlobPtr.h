#ifndef CONST_BLOB_PTR
#define CONST_BLOB_PTR

#include "Blob.h"
#include "BlobPtr.h"

template <typename T>
bool operator==(const ConstBlobPtr<T> &, const ConstBlobPtr<T> &);

template <typename T>
class ConstBlobPtr
{
public:
    friend bool operator==<T>(const ConstBlobPtr &, const ConstBlobPtr &);
    friend bool operator!=<T>(const ConstBlobPtr &, const ConstBlobPtr &);
    friend bool operator< <T>(const ConstBlobPtr &, const ConstBlobPtr &);
    friend bool operator><T>(const ConstBlobPtr &, const ConstBlobPtr &);
    friend bool operator<=<T>(const ConstBlobPtr &, const ConstBlobPtr &);
    friend bool operator>=<T>(const ConstBlobPtr &, const ConstBlobPtr &);

public:
    ConstBlobPtr();
    ConstBlobPtr(Blob<T> &, std::size_t = 0);
    T &operator[](std::size_t);
    const T &operator[](std::size_t) const;
    T deref() const;
    ConstBlobPtr &incr();
    const T &operator*() const;
    const T *operator->() const;

private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
ConstBlobPtr<T>::ConstBlobPtr() : curr(0) {}

template <typename T>
ConstBlobPtr<T>::ConstBlobPtr(Blob<T> &a, std::size_t sz) : wptr(a.data), curr(sz) {}

template <typename T>
std::shared_ptr<std::vector<T>> ConstBlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lcok();
    if (!ret)
    {
        throw std::runtime_error("Unbound ConstBlobPtr");
    }
    if (i >= ret->size())
    {
        throw std::out_of_range(msg);
    }
    return ret;
}

template <typename T>
T ConstBlobPtr<T>::deref() const
{
    auto p = check(curr, "Dereference past end of ConstBlobPtr");
    return (*p)[curr];
}

template <typename T>
ConstBlobPtr<T> &ConstBlobPtr<T>::incr()
{
    auto p = check(curr, "Increment past end of ConstBlobPtr");
    ++curr;
    return *this;
}

template <typename T>
bool operator==(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    if ((*lhs.wptr.lock() == *rhs.wptr.lock()) && (lhs.curr == rhs.curr))
        return true;
    return false;
}

template <typename T>
bool operator!=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr < rhs.curr;
}

template <typename T>
bool operator>(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator<=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(lhs > rhs);
}

template <typename T>
bool operator>=(const ConstBlobPtr<T> &lhs, const ConstBlobPtr<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
T &ConstBlobPtr<T>::operator[](std::size_t n)
{
    return (*wptr.lock())[n];
}

template <typename T>
const T &ConstBlobPtr<T>::operator[](std::size_t n) const
{
    return (*wptr.lock())[n];
}

template <typename T>
const T &ConstBlobPtr<T>::operator*() const
{
    auto p = check(curr, "Dereference past end of ConstBlobPtr");
    return (*p)[curr];
}

template <typename T>
const T *ConstBlobPtr<T>::operator->() const
{
    return &this->operator*();
}

#endif