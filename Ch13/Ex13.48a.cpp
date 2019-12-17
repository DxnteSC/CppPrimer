#include <vector>
#include "Ex13.47.h"

int main()
{
    charString a("Hi");
    charString b("Hello");
    charString c("Hey");
    charString d("Dante");
    std::vector<charString> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    for(auto i = v.begin(); i != v.end();++i)
    {
        std::cout << i->str() << std::endl;
    }
}