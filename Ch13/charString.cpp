#include "charString.h"


std::allocator<char> charString::alloc;

charString::charString(const char* c) : charString()
{
    while (*c != '\0')
        push_back(*c++);
}

void charString::push_back(const char& c)
{
    checkAndAllocate();
    alloc.construct(firstFree++, c);
}
void charString::reallocate()
{
    auto newCapacity = size() ? size() * 2 : 1;
    auto newFirstChar = alloc.allocate(newCapacity);
    auto newFirstFree = newFirstChar;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(newFirstFree++,std::move(*firstChar++));
    free();
    firstChar = newFirstChar;
    firstFree = newFirstFree;
    cap = firstChar + newCapacity;
}

void charString::free()
{
    if (firstChar)
    {
        for (auto p = firstFree; p != firstChar;)
            alloc.destroy(--p);
        alloc.deallocate(firstChar,cap-firstChar);
        firstChar = firstFree = cap = nullptr;
    }
}

std::string charString::str() const 
{
    return std::string(begin(),end());
}
int main()
{
    const char c[] = {'h','i'};
    charString Test(c);
    std::cout << Test.str() << std::endl;
}