#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class ValueHasPtr
{
public:
    ValueHasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num) { }
    ValueHasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
    ValueHasPtr(const ValueHasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    ValueHasPtr& operator= (const ValueHasPtr&);
    ~ValueHasPtr()
    {
        delete ps;
    }
private:
    std::string* ps;
    int    i;
};

class PointerHasPtr
{
    PointerHasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num), use(new std::size_t(1)) { }
    PointerHasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0), use(new std::size_t(1)) { }
    PointerHasPtr(const PointerHasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i), use(hp.use) { ++use; }
    PointerHasPtr& operator= (const PointerHasPtr&);
    ~PointerHasPtr();
    
private:
    std::string* ps;
    int    i;
    std::size_t* use;
}

#endif
