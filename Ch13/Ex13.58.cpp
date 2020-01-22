#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

class Foo
{
public:
    Foo () = default;
    Foo (std::vector<int> i): data(i) {}
    Foo (std::initializer_list<int> il): data(il) {}
    Foo sorted() &&;
    Foo sorted() const &;

    void print() const;
private:
    std::vector<int> data;
};

Foo Foo::sorted() && 
{
    std::cout << "RVal" << std::endl;
    sort(data.begin(), data.end());
    return *this;
}

Foo Foo::sorted() const & 
{
    std::cout << "LVal" << std::endl;
    Foo ret(*this);
    sort(ret.data.begin(),ret.data.end());
    return ret;
} 

/* Ex13.56
Foo Foo::sorted() const & 
{
    Foo ret(*this);
    return ret.sorted();
} */

/* Ex13.57
Foo Foo::sorted() const & 
{ 
    return Foo(*this).sorted(); 
}
*/

void Foo::print() const 
{
    for (const auto i: data)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main()
{
    Foo a{ 3,2,4,5,1 }; 
    a.print();
    Foo b = a.sorted(); 
    a.print(); 
    b.print();
    Foo c = Foo({ 5,2,1,4,3 }).sorted(); 
    c.print();
}