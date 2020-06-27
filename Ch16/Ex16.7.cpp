#include <iostream>

template <typename T, size_t N>
constexpr size_t getArrSize(const T (&a)[N])
{
    return N;
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    constexpr size_t size = getArrSize(a);
    std::cout << size << std::endl;
}