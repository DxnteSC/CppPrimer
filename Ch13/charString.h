#include <iostream>
#include <memory>
#include <utility>

class charString
{
public:
    charString(): firstChar(nullptr),firstFree(nullptr),cap(nullptr) {}
    charString(const char*);
    // charString(const charString&);
    // charString& operator=(const charString&);
    // ~charString();
    void push_back(const char&);
    size_t size() const { return firstFree - firstChar; }
    size_t capacity() const { return cap - firstChar; }
    char* begin() const { return firstChar; }
    char* end() const { return firstFree; }
    std::string str() const;
private:
    char* firstChar; // pointer to first elememt
    char* firstFree; // pointer to one after last element
    char* cap; // pointer to one past the end of the array
    static std::allocator<char> alloc; // allocate the elements
    void reallocate(); // get more space and copies the elements
    void free(); // destroy the elements and free space
    std::pair<char*,char*> allocateAndCopy(); // allocate space and copy a given range of elements
    void checkAndAllocate()
    {
        if (size() == capacity())
            reallocate();
    }
};
