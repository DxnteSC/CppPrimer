#include <algorithm>
#include <iostream>
#include <vector>

#include "HasPtr.h"

int main()
{
    ValueHasPtr a("Dante", 5);
    ValueHasPtr b("Tosan", 13);
    ValueHasPtr c("Kunle", 7);
    std::vector<ValueHasPtr> v = {a,b,c};
    std::cout << "Before Sort" << std::endl;
    for (auto hp: v)
    {
        std::cout << hp.GetString() << " " << hp.GetInt() << std::endl;
    }
    std::sort(v.begin(), v.end());
    std::cout << "After Sort" << std::endl;
    for (auto hp: v)
    {
        std::cout << hp.GetString() << " " << hp.GetInt() << std::endl;
    }
}
