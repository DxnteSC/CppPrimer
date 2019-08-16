#include <iostream>
#include <memory>
#include <string>

int main()
{
    /* string *const p = new string[n]; // construct n empty strings
    string s;
    string *q = p;                   // q points to the first string
    while (cin >> s && q != p + n)
        *q++ = s;                      // assign a new value to *q
    const size_t size = q - p;       // remember how many strings we read
    // use the array
    delete[] p;  // p points to an array; must remember to use delete[] */
    
    std::string s;
    constexpr std::size_t n = 10;
    std::allocator<std::string> strAlloc;
    
    auto const p = strAlloc.allocate(n);
    auto q = p;
    while (std::cin >> s && q != p + n)
    {
        strAlloc.construct(q++,s);
    }
    for (auto i = p; i != q; ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    while (q != p)
    {
        strAlloc.destroy(--q);
    }
    strAlloc.deallocate(p, n);
}
