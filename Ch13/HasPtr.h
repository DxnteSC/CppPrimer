#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class ValueHasPtr
{
public:
    friend void swap(ValueHasPtr&, ValueHasPtr&);
public:
    ValueHasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num) { }
    ValueHasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
    ValueHasPtr(const ValueHasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    ValueHasPtr& operator= (const ValueHasPtr&);
    bool operator< (const ValueHasPtr&) const;
    ~ValueHasPtr()
    {
        delete ps;
    }
    inline void swap(ValueHasPtr& rhs)
    {
        std::cout << "Internal Swap" << std::endl;
        using std::swap;
        swap(ps, rhs.ps);
        swap(i,rhs.i);
    }
    std::string GetString() {return *ps; }
    int GetInt() { return i; }
private:
    std::string* ps;
    int i;
};

class PointerHasPtr
{
public:
    PointerHasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num), use(new std::size_t(1)) { }
    PointerHasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    PointerHasPtr(const PointerHasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i), use(hp.use) { ++use; }
    PointerHasPtr& operator= (const PointerHasPtr&);
    ~PointerHasPtr();
private:
    std::string* ps;
    int i;
    std::size_t* use;
};

#endif
