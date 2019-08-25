#include <iostream>

class numbered
{
public:
    numbered(int i = 0): mysn(i) {}
    numbered(const numbered& n)
    {
        int temp = n.mysn;
        mysn = ++temp;
    }
    int sn() const { return mysn; }
private:
    int mysn;
};

void f(numbered s)
{
    std::cout << s.sn() << std::endl;
}

void x(const numbered& s)
{
    std::cout << s.sn() << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    // f(a); f(b); f(c); // 0, 0, 0 without copy constructor, 1,2,3 with copy constructor.
    x(a); x(b); x(c); // 0,1,2 all predictions correct.
}
