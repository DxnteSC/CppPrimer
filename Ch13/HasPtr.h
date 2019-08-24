#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string(), int num = 0):
    ps(new std::string(s)), i(num) { }
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator= (const HasPtr&);
    
private:
    std::string* ps;
    int    i;
};

#endif
