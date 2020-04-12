#include <iostream>

class Base
{

public:
    Base(int a, char b, int c) : i(a), c(b), p(c) {}
    void memfcn(Base &b) { b = *this; }

protected:
    int i;
    char c;

private:
    int p;
};
struct Pub_Derv : public Base
{
public:
    Pub_Derv(int a, char b, int c) : Base(a, b, c) {}
    void memfcn(Base &b) { b = *this; }

private:
    int p;
};
struct Priv_Derv : private Base
{
public:
    Priv_Derv(int a, char b, int c) : Base(a, b, c) {}
    void memfcn(Base &b) { b = *this; }

private:
    int p;
};

struct Prot_Derv : protected Base
{
public:
    Prot_Derv(int a, char b, int c) : Base(a, b, c) {}
    void memfcn(Base &b) { b = *this; }

private:
    int p;
};

struct Derived_from_Public : public Pub_Derv
{
public:
    Derived_from_Public(int a, char b, int c) : Pub_Derv(a, b, c) {}
    void memfcn(Base &b) { b = *this; }

private:
    int p;
};
struct Derived_from_Private : public Priv_Derv
{
public:
    Derived_from_Private(int a, char b, int c) : Priv_Derv(a, b, c) {}
    // void memfcn(Base &b) { b = *this; } illegal.

private:
    int p;
};

struct Derived_from_Protected : public Prot_Derv
{
public:
    Derived_from_Protected(int a, char b, int c) : Prot_Derv(a, b, c) {}

private:
    int p;
};

int main()
{
    Pub_Derv d1(0, 'p', 0);
    Priv_Derv d2(0, 'p', 1);
    Prot_Derv d3(0, 'p', 2);
    Derived_from_Public dd1(1, 'd', 0);
    Derived_from_Private dd2(1, 'd', 1);
    Derived_from_Protected dd3(1, 'd', 2);
    Base *p = &d1; //  d1 has type Pub_Derv (a)
    //p = &d2;       //  d2 has type Priv_Derv (b)
    //p = &d3;       //  d3 has type Prot_Derv (c)
    p = &dd1; //  dd1 has type Derived_from_Public (d)
    //p = &dd2;      //  dd2 has type Derived_from_Private (e)
    //p = &dd3;      //  dd3 has type Derived_from_Protected (f)
}
