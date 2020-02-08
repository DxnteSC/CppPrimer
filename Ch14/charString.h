#ifndef CHAR_STR_H
#define CHAR_STR_H

#include <memory>
#include <string>

class charString
{
public:
    friend bool operator==(const charString&, const charString&);
    friend bool operator!=(const charString&, const charString&);
    friend bool operator<(const charString&, const charString&);
    friend bool operator>(const charString&, const charString&);
    friend bool operator<=(const charString&, const charString&);
    friend bool operator>=(const charString&, const charString&);
public:
    charString(): firstElem(nullptr), firstFree(nullptr), cap(nullptr) {}
    charString(const char*);
    ~charString() { free(); }
    charString(const charString&);
    charString& operator=(const charString&);
    charString(charString&&) noexcept;
    charString& operator=(charString&&) noexcept;
    char& operator[] (std::size_t);
    const char& operator[] (std::size_t) const;
    void push_back(const char&);
    void pop_back();
    char* begin() const { return firstElem; }
    char* end() const { return firstFree; }
    const char* cbegin() const { return begin(); }
    const char* cend() const { return end(); }
    size_t size() const 
    { 
        return firstFree - firstElem; 
    }
    size_t capacity() const 
    {
        return cap - firstElem; 
    }
    
    std::string str() const 
    {
        return std::string(begin(),end());
    }

private:
    char* firstElem;
    char* firstFree;
    char* cap;
    static std::allocator<char> alloc;
    void checkAndAllocate()
    {
        if (size() == capacity())
        {
            reallocate();
        }
    }
    void reallocate();
    void free();
    std::pair<char*,char*> allocateAndCopy(const char*, const char*);
};

bool operator==(const charString&, const charString&);
bool operator!=(const charString&, const charString&);
bool operator<(const charString&, const charString&);
bool operator>(const charString&, const charString&);
bool operator<=(const charString&, const charString&);
bool operator>=(const charString&, const charString&);

#endif