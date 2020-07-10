#ifndef VEC
#define VEC

#include <initializer_list>
#include <memory>
#include <utility>

template <typename T>
class Vec;

template <typename T>
bool operator==(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator!=(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator<(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator>(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator<=(const Vec<T> &, const Vec<T> &);
template <typename T>
bool operator>=(const Vec<T> &, const Vec<T> &);

template <typename T>
class Vec
{
public:
    friend bool operator==<T>(const Vec &, const Vec &);
    friend bool operator!=<T>(const Vec &, const Vec &);
    friend bool operator< <T>(const Vec &, const Vec &);
    friend bool operator><T>(const Vec &, const Vec &);
    friend bool operator<=<T>(const Vec &, const Vec &);
    friend bool operator>=<T>(const Vec &, const Vec &);

public:
    Vec() : elements(nullptr), firstFree(nullptr), cap(nullptr) {}
    Vec(std::initializer_list<T>);
    Vec(const Vec &);
    Vec &operator=(const Vec &);
    ~Vec() { free(); }
    Vec(Vec &&) noexcept;
    Vec &operator=(Vec &&) noexcept;
    Vec &operator=(std::initializer_list<T>);
    T &operator[](std::size_t);
    const T &operator[](std::size_t) const;
    void push_back(const T &);
    void push_back(T &&);
    void pop_back();
    size_t size() const { return firstFree - elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return firstFree; }
    void reserve(size_t);
    void resize(size_t, const T & = T());

private:
    static std::allocator<T> alloc;
    void CheckAndAllocate()
    {
        if (size() == capacity())
            reallocate();
    }
    std::pair<T *, T *> AllocateAndCopy(const T *, const T *);
    void free();
    void reallocate();
    T *elements;
    T *firstFree;
    T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(std::initializer_list<T> il) : Vec<T>()
{
    for (const auto &t : il)
        push_back(t);
}

template <typename T>
void Vec<T>::push_back(const T &t)
{
    CheckAndAllocate();
    alloc.construct(firstFree++, t);
}

template <typename T>
void Vec<T>::push_back(T &&t)
{
    CheckAndAllocate();
    alloc.construct(firstFree++, std::move(t));
}

template <typename T>
void Vec<T>::pop_back()
{
    if (size() > 0)
        alloc.destroy(--firstFree);
}

template <typename T>
std::pair<T *, T *> Vec<T>::AllocateAndCopy(const T *b, const T *e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free()
{
    if (elements)
    {
        for (auto p = firstFree; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec &v)
{
    auto newData = AllocateAndCopy(v.begin(), v.end());
    elements = newData.first;
    firstFree = cap = newData.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs)
{
    auto data = AllocateAndCopy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    firstFree = cap = data.second;
    return *this;
}

template <typename T>
void Vec<T>::reallocate()
{
    auto newCap = size() ? size() * 2 : 1;
    auto first = alloc.allocate(newCap);
    auto last = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), first);
    free();
    elements = first;
    firstFree = last;
    cap = elements + newCap;
}

template <typename T>
void Vec<T>::reserve(size_t sz)
{
    if (sz > capacity())
    {
        auto newData = alloc.allocate(sz);
        auto dest = newData;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newData;
        firstFree = dest;
        cap = elements + sz;
    }
}

template <typename T>
void Vec<T>::resize(size_t sz, const T &t)
{
    if (sz > size())
    {
        for (int i = sz - size(); i != 0; --i)
            push_back(t);
    }
    else if (sz < size())
    {
        for (int i = size() - sz; i != 0; --i)
            pop_back();
    }
}

template <typename T>
Vec<T>::Vec(Vec &&v) noexcept : elements(v.elements), firstFree(v.firstFree), cap(v.cap)
{
    v.elements = v.firstFree = v.cap = nullptr;
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&rhs) noexcept
{
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        firstFree = rhs.firstFree;
        cap = rhs.cap;
        rhs.elements = rhs.firstFree = rhs.cap = nullptr;
    }
    return *this;
}

template <typename T>
bool operator==(const Vec<T> &lhs, Vec<T> &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (auto i = lhs.begin(), j = rhs.begin(); i != lhs.end(); i++, j++)
    {
        if (i != j)
            return false;
    }
    return true;
}

template <typename T>
bool operator!=(const Vec<T> &lhs, Vec<T> &rhs)
{
    return !(lhs == rhs);
}

template <typename T>
bool operator<(const Vec<T> &lhs, Vec<T> &rhs)
{
    return lhs.size() < rhs.size();
}

template <typename T>
bool operator>(const Vec<T> &lhs, Vec<T> &rhs)
{
    return rhs < lhs;
}

template <typename T>
bool operator<=(const Vec<T> &lhs, Vec<T> &rhs)
{
    return !(lhs > rhs);
}

template <typename T>
bool operator>=(const Vec<T> &lhs, Vec<T> &rhs)
{
    return !(lhs < rhs);
}

template <typename T>
Vec<T> &Vec<T>::operator=(std::initializer_list<T> il)
{
    auto data = AllocateAndCopy(il.begin(), il.end());
    free();
    elements = data.first;
    firstFree = cap = data.second;
    return *this;
}

template <typename T>
T &Vec<T>::operator[](size_t n)
{
    return elements[n];
}

template <typename T>
const T &Vec<T>::operator[](size_t n) const
{
    return elements[n];
}

#endif