#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string> 

class HasPtr
{
public:
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num) { }
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    
    HasPtr& operator=(HasPtr& rhs) {
        std::swap(*this,rhs); 
        return *this;
    } 

    HasPtr& operator= (const HasPtr& rhs)
    {
        auto copy = new std::string(*rhs.ps);
        delete ps;
        ps = copy;
        i = rhs.i;
        return *this;
    }
    HasPtr& operator= (HasPtr&& rhs) noexcept
    {
        if (this != &rhs)
        {
            ps = rhs.ps;
            i = rhs.i;
            rhs.ps = nullptr;
        }
        return *this;
    }

    bool operator< (const HasPtr&) const;
    ~HasPtr()
    {
        delete ps;
    }
    HasPtr(HasPtr&& p) noexcept: ps(p.ps), i(p.i) { // move constructor
        p.ps = 0;
    }

    inline void swap(HasPtr& rhs)
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

#endif