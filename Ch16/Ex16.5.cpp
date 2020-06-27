#include <iostream>

template <typename T, std::size_t N> 
void print(const T (&a)[N] )
{
    for (int i = 0; i != N; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    print(a);
    print({50,51,52,53,54,55});
}