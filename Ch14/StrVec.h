#ifndef STR_VEC_H
#define STR_VEC_H

#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec
{
public:
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    friend bool operator>(const StrVec&, const StrVec&);
    friend bool operator<=(const StrVec&, const StrVec&);
    friend bool operator>=(const StrVec&, const StrVec&);
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {} // alloc is defualt initialised
    StrVec(std::initializer_list<std::string>);
    StrVec(const StrVec&); // copy constructor
    StrVec& operator=(const StrVec&); // copy assignment
    ~StrVec(); // destructor
    StrVec(StrVec&&) noexcept; // move constructor
    StrVec& operator=(StrVec&&) noexcept;
    StrVec& operator=(std::initializer_list<std::string>);
    void push_back(const std::string&); // copy the element
    void push_back(std::string&&); // move the element
    void pop_back(); // remove last element
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t, const std::string& = std::string());
private:
    static std::allocator<std::string> alloc; // allocate the elements
    void chk_n_alloc() // used by functions which add elements to a StrVec
    {
        if (size() == capacity())
            reallocate();
    }
    // utilities used by copy constructor, assignment operator and destructor
    std::pair<std::string*, std::string*> alloc_n_copy(const std::string*,const std::string*);
    void free(); // destroy the elements and free the space
    void reallocate(); // get more space and copies the elements
    std::string* elements; // pointer to the first element in the array
    std::string* first_free; // pointer to the first free elemet in the array
    std::string* cap; // pointer to one past the end of the array
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);
bool operator<(const StrVec&, const StrVec&);
bool operator>(const StrVec&, const StrVec&);
bool operator<=(const StrVec&, const StrVec&);
bool operator>=(const StrVec&, const StrVec&);

#endif
