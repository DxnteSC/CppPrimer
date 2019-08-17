#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <initializer_list>
#include <memory>
#include <string>
#include <vector>


class StrBlob;
class StrBlobPtr;

class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
public:
    friend class StrBlobPtr;
    friend class ConstStrBlobPtr;
public:
    StrBlob(): data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il): data(std::make_shared<std::vector<std::string>>(il)) {}
    size_type size() const { return data -> size(); }
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

class ConstStrBlobPtr
{
public:
    ConstStrBlobPtr(): wptr(), curr(0) {}
    ConstStrBlobPtr(const StrBlob& a, size_t sz = 0): wptr(a.data), curr(sz) {}
    const std::string deref() const;
    ConstStrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

#endif
