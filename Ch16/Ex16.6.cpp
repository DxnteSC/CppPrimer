#include <iostream>

template <typename T, std::size_t N>
T* begin( T (&a)[N]) 
{
    return a;
} 

template <typename T, std::size_t N>
T* end( T (&a)[N]) 
{
    return a + N;
} 

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    for (auto beg = begin(arr); beg != end(arr); beg++)
    {
        std::cout << *beg << " ";
    }
    std::cout << std::endl;
}