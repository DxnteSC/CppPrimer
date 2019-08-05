#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> dynamicVect()
{
    return std::make_shared<std::vector<int>>();
}

void read(std::istream& is, std::shared_ptr<std::vector<int>> v)
{
    int i;
    while (is >> i)
    {
        v->push_back(i);
    }
}

std::ostream& print(std::ostream& os, const std::shared_ptr<std::vector<int>> v)
{
    for (auto i: *v)
    {
        os << i << " ";
    }
    os << std::endl;
    return os;
}

int main()
{
    auto ivec = dynamicVect();
    read(std::cin, ivec);
    print(std::cout, ivec);
}

