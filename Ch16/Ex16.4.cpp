#include <iostream>
#include <list>
#include <string>
#include <vector>

template <typename iter, typename T> 
iter myFind(const iter& beg, const iter& end, const T& val) 
{
    for (iter i = beg; i != end; i++)
    {
        if (*i == val)
            return i;
    }
    return end;
}

int main()
{
    std::list<std::string> slist = {"hi", "bye", "hello"};
    std::vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    auto i = myFind(ivec.begin(),ivec.end(),5);
    std::cout << *i << std::endl;
    auto j = myFind(slist.begin(),slist.end(),"bye");
    std::cout <<  *j << std::endl;
}