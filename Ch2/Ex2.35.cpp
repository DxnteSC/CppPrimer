#include <iostream>
#include <typeinfo>

int main()
{
    const int i = 42; // const int
    std::cout << "Type of i is: " << typeid(i).name() << std::endl;
    auto j = i; // j is an int
    std::cout << "Type of j is: " << typeid(j).name() << std::endl;
    const auto &k = i; // k is a const int reference bound to i;
    std::cout << "Type of k is: " << typeid(k).name() << std::endl;
    auto *p = &i; // p is an int pointer to i
    std::cout << "Type of p is: " << typeid(p).name() << std::endl;
    const auto j2 = i, &k2 = i; // j2 is a const int, k2 is a const int refencce to i.
    std::cout << "Type of j2 is: " << typeid(j2).name() << std::endl;
    std::cout << "Type of k2 is: " << typeid(k2).name() << std::endl;
    
    return 0;
}
