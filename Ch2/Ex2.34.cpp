#include <iostream>

int main()
{
    int i = 0, &r = i;
    const int ci = i, &cr = ci;
    
    auto a = r; // int
    std::cout << "a: " << a << std::endl;
    a = 42
    std::cout << "a: " << a << std::endl;
    auto b = ci; // int
    std::cout << "b: " << b << std::endl;
    b = 42;
    std::cout << "b: " << b << std::endl;
    auto c = cr; // int
    std::cout << "c: " << c << std::endl;
    c = 42;
    std::cout << "c: " << c << std::endl;
    auto d = &i; // int*
    std::cout << "d: " << d << std::endl;
    d = 42;
    std::cout << "d: " << d << std::endl;
    auto e = &ci; // const inst*
    std::cout << "e: " << e << std::endl;
    e = 42;
    std::cout << "e: " << e << std::endl;
    auto &g = ci; // const int &
    std::cout << "g: " << g << std::endl;
    g = 42;
    std::cout << "g: " << g << std::endl;
    return 0;
}
