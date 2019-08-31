#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlob;
class StrBlobPtr;

typedef std::vector<std::string>::size_type size_type;

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    friend class StrBlobPtr;
public:
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data -> size(); }
    StrBlob(const StrBlob& sb): data(std::make_shared<std::vector<std::string>>(*sb.data)) {}
    StrBlob& operator= (const StrBlob& rhs) { data = std::make_shared<std::vector<std::string>>(*rhs.data); return *this; }
public:
    bool empty() const { return data -> empty(); }
    // Add and remove elements
    void push_back(const std::string& s) { data -> push_back(s); }
    void pop_back();
    // Element access
    std::string& front();
    std::string& back();
    const std::string& front() const ;
    const std::string& back() const;
    StrBlobPtr begin();
    StrBlobPtr end();
private:
    std::shared_ptr<std::vector<std::string>> data;
    // Error message if data[i] is unabailable
    void check(size_type, const std::string&) const;
};

class StrBlobPtr
{
public:
    StrBlobPtr(): curr(0) {}
    explicit StrBlobPtr(StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) {}
    std::string deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


StrBlob& StrBlob::operator= (const StrBlob&);

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


#endif

