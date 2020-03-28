#include <iostream>

class functionObject
{
public:
    int operator()(int, int, int) const;
};

int functionObject::operator()(int i, int j, int k) const
{
    return i < 0 ? j : k;
}

int main()
{
    int a = 5, b = 1, c = 10;
    functionObject f;
    std::cout << f(a, b, c) << std::endl;
}