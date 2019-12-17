#include "Ex13.50.h"

std::allocator<char> charString::alloc;

charString::charString(const char* c): charString()
{
    while (*c != '\0')
    {
        push_back(*c++); 
    }
}

charString::charString(const charString& cs)
{
    std::cout << "COPY CONSTRUCTOR" << std::endl;
    auto newData = allocateAndCopy(cs.begin(),cs.end());
    firstElem = newData.first;
    firstFree = cap = newData.second;
}

charString& charString::operator=(const charString& rhs)
{
    std::cout << "COPY-ASSIGNMENT CONSTRUCTOR" << std::endl;
    auto newData = allocateAndCopy(rhs.begin(),rhs.end());
    free();
    firstElem = newData.first;
    firstFree = cap = newData.second;
    return *this;
}

std::pair<char*,char*> charString::allocateAndCopy (const char* b, const char* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b,e,data)};
}

void charString::push_back(const char& c)
{
    checkAndAllocate();
    alloc.construct(firstFree++,c);
}

void charString::pop_back()
{
    if (size() > 0)
        alloc.destroy(--firstFree);
}

void charString::reallocate()
{
    auto newCap = size() ? capacity() * 2 : 1;
    auto newFirstElem = alloc.allocate(newCap);
    auto newFirstFree = newFirstElem;
    auto elem = firstElem;
    for (size_t i = 0; i != size(); ++i) // nope
    {
        alloc.construct(newFirstFree++, std::move(*elem++));
    }
    free();
    firstElem = newFirstElem; 
    firstFree = newFirstFree;
    cap = firstElem + newCap;
}

void charString::free()
{
    if (firstElem)
    {
        for (auto p = firstFree; p != firstElem;)
        {
            alloc.destroy(--p);
        }
        alloc.deallocate(firstElem, capacity());
        firstElem = firstFree = cap = nullptr;
    }
}

charString::charString(charString&& c) noexcept: firstElem(c.firstElem), firstFree(c.firstFree),cap(c.cap)
{
    std::cout << "MOVE CONSTRUCTOR" << std::endl;
    c.firstElem = c.firstFree = c.cap = nullptr;
}

charString& charString::operator=(charString&& rhs) noexcept
{
    std::cout << "MOVE-ASSIGNMENT CONSTRUCTOR" << std::endl;
    if (this != &rhs)
    {
        free();
        firstElem = rhs.firstElem;
        firstFree = rhs.firstFree;
        cap = rhs.cap;
        rhs.firstElem = rhs.firstFree = rhs.cap = nullptr;
    }
    return *this;
}