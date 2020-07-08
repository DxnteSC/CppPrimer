#ifndef BLOB
#define BLOB

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <vector>
#include <utility>

template <typename T>
class Blob;

template <typename T>
class BlobPtr;

template <typename T>
class ConstBlobPtr;

template <typename T>
bool operator==(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator!=(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator>(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator<=(const Blob<T> &, const Blob<T> &);
template <typename T>
bool operator>=(const Blob<T> &, const Blob<T> &);

template <typename T>
class Blob
{
public:
    friend class BlobPtr<T>;
    friend class ConstBlobPtr<T>;
    friend bool operator==<T>(const Blob &, const Blob &);
    friend bool operator!=<T>(const Blob &, const Blob &);
    friend bool operator< <T>(const Blob &, const Blob &);
    friend bool operator><T>(const Blob &, const Blob &);
    friend bool operator<=<T>(const Blob &, const Blob &);
    friend bool operator>=<T>(const Blob &, const Blob &);

public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    Blob();
    Blob(std::initializer_list<T>);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); }
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void push_back(const T &t) const { data->push_back(t); }
    void push_back(T &&t) const { data->push_back(std::move(t)); }
    void pop_back();
    void pop_back() const;
    T &front();
    T &back();
    const T &front() const;
    const T &back() const;
    T &operator[](size_type i);
    const T &operator[](size_type i) const;
    BlobPtr<T> begin() { return BlobPtr<T>(*this); }
    const BlobPtr<T> cbegin() const { return BlobPtr<T>(*this); }
    BlobPtr<T> end() { return BlobPtr<T>(*this, size()); }
    const BlobPtr<T> cend() const { return BlobPtr<T>(*this, size()); }

private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type, const std::string &) const;
};

template <typename T>
Blob<T>::Blob() : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "called pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
void Blob<T>::pop_back() const
{
    check(0, "called pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "called front on empty Blob");
    return data->front();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "called back on empty Blob");
    return data->back();
}

template <typename T>
const T &Blob<T>::front() const
{
    check(0, "called front on empty Blob");
    return data->front();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "called back on empty Blob");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
bool operator==(const Blob<T> &lhs, const Blob<T> &rhs)
{
    if (*lhs.data == *rhs.data)
        return true;
    return false;
}
template <typename T>
bool operator!=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs == rhs);
}
template <typename T>
bool operator<(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return (*lhs.data < *rhs.data);
}
template <typename T>
bool operator>(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return rhs < lhs;
}
template <typename T>
bool operator<=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs > rhs);
}
template <typename T>
bool operator>=(const Blob<T> &lhs, const Blob<T> &rhs)
{
    return !(lhs < rhs);
}

#endif