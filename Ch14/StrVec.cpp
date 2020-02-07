#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(std::initializer_list<std::string> il): StrVec()
{
    for (const auto &s: il)
        push_back(s);
}
void StrVec::push_back(const std::string& s)
{
    chk_n_alloc(); // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++,s); // increments first free to show that a new element has been added; postfix so the element is constructed in the current valye of first_free and then first_free is incremented to point to the next unconstructed element
}

void StrVec::push_back(std::string&& s)
{
    chk_n_alloc(); // reallocates the StrVec if necessary
    alloc.construct(first_free++,std::move(s));
}

void StrVec::pop_back()
{
    if (size() > 0)
        alloc.destroy(--first_free);
}

std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    // allocate space to hold as many elements within the range
    auto data = alloc.allocate(e - b);
    // initialise and return a pair constructucted from data and the value returned from unititialized_copy
    return {data, std::uninitialized_copy(b,e,data)};
}

void StrVec::free()
{
    // can't pass deallocate a 0 pointer, if elements is 0, there's no work to do
    if (elements)
    {
        // destroy the old elements in reverse order
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec& sv)
{
    // call alloc_n_copy to allocate exactly as many elements in sv
    auto newData = alloc_n_copy(sv.begin(),sv.end());
    elements = newData.first;
    first_free = cap = newData.second;
}

StrVec::~StrVec() { free(); }

StrVec& StrVec::operator=(const StrVec& rhs)
{
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

/*void StrVec::reallocate()
{
    // allocate space for twice as many elements, or 1 if the StrVec is empty
    auto newcapacity = size() ? size() * 2 : 1;
    // allocate new memory
    auto newData = alloc.allocate(newcapacity);
    // move the data from the old memory to the new
    auto dest = newData; // points to the next free position in the new array
    auto elem = elements; // points to the next element in the old array
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // free the old space once we've moved all of the elemnents
    // update our data structure to point to the new elements
    elements = newData;
    first_free = dest;
    cap = elements + newcapacity;
}*/

void StrVec::reallocate()
{
    auto newCap = size() ? size() * 2: 1;
    auto first = alloc.allocate(newCap);
    // move the elements
    auto last = std::uninitialized_copy(make_move_iterator(begin()),make_move_iterator(end()),first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newCap;
}

void StrVec::reserve(size_t sz)
{
    if (sz > capacity())
    {
        auto newData = alloc.allocate(sz);
        auto dest = newData;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newData;
        first_free = dest;
        cap = elements + sz;
    }
}

void StrVec::resize(size_t sz, const std::string& s)
{
    if (sz > size())
    {
        for (int i = sz - size(); i != 0; --i)
            push_back(s);
    }
    else if (sz < size())
    {
        for (int i = size() - sz; i != 0; --i)
            pop_back();
    }
}

StrVec::StrVec(StrVec&& s) noexcept // move wno't throw any exceptions
: elements(s.elements), first_free(s.first_free),cap(s.cap) 
// member initializers take over the resources in s
{
    // leave s in a state in which it is sage to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept
{
    // direct test for self-assignment
    if (this != &rhs)
    {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        //leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec& lhs, const StrVec& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (auto i = lhs.begin(), j = rhs.begin(); i != lhs.end(); i++, j++)
    {
        if (i != j)
            return false;
    }
    return true;
}

bool operator!=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec& lhs, const StrVec& rhs)
{
    return lhs.size() < rhs.size();
}

bool operator>(const StrVec& lhs, const StrVec& rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const StrVec& lhs, const StrVec& rhs)
{
    return !(lhs < rhs);
}