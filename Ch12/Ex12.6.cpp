#include <iostream>
#include <vector>

std::vector<int>* dynamicVect()
{
    return new std::vector<int>();
}

void read(std::istream& is, std::vector<int>* v)
{
    int i;
    while (is >> i)
    {
        v->push_back(i);
    }
}

std::ostream& print(std::ostream& os, const std::vector<int>* v)
{
    for (auto i: *v)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
    delete v;
}

int main()
{
    auto ivec = dynamicVect();
    read(std::cin, ivec);
    print(std::cout, ivec);
}

