#include <iostream>
#include "Blob.h"
#include "BlobPtr.h"
#include "ConstBlobPtr.h"

template <typename T>
void TestBlobFunctions(const Blob<T> &b, const T &first)
{
    T input = first;
    std::cout << "Size: " << b.size() << std::endl;
    std::cout << "Front: " << b.front() << std::endl;
    std::cout << "Back: " << b.back() << std::endl;
    std::cout << "Before: ";
    for (int i = 0; i != b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    b.push_back(input);
    std::cout << "After: ";
    for (int i = 0; i != b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Changed: ";
    for (int i = 0; i != b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    b.pop_back();
    std::cout << "Original: ";
    for (int i = 0; i != b.size(); i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void TestBlobRelations(const Blob<T> &a, const Blob<T> &b)
{
    std::cout << (a == b ? "true" : "false") << std::endl;
    std::cout << (a != b ? "true" : "false") << std::endl;
    std::cout << (a < b ? "true" : "false") << std::endl;
    std::cout << (a > b ? "true" : "false") << std::endl;
    std::cout << (a <= b ? "true" : "false") << std::endl;
    std::cout << (a >= b ? "true" : "false") << std::endl;
}

template <typename T>
void TestBlobPtr(BlobPtr<T> bp)
{
    std::cout << "First Elem: " << bp.deref() << std::endl;
    bp.incr();
    std::cout << "Second Elem: " << *bp << std::endl;
    bp++;
    std::cout << "Third Elem: " << *bp << std::endl;
    bp--;
    std::cout << "Second Elem: " << *bp << std::endl;
    bp++;
    std::cout << "Third Elem: " << *bp << std::endl;
    bp--;
    std::cout << "Second Elem: " << *bp << std::endl;
    bp += 2;
    std::cout << "Fourth Elem: " << *bp << std::endl;
    bp -= 3;
    std::cout << "First Elem: " << *bp << std::endl;
    bp = bp + 4;
    std::cout << "Fifth Elem: " << *bp << std::endl;
    bp = bp - 2;
    std::cout << "Third Elem: " << *bp << std::endl;
}

int main()
{
    Blob<int> a1{1, 2, 3, 4, 5}, a2{1, 2, 3, 4, 5}, b{6, 7, 8, 9, 10};
    Blob<std::string> c1{"hello", "hey", "hi"}, c2{"hello", "hey", "hi"}, d{"goodbye", "bye"};

    BlobPtr<int> aPtr(a1);
    BlobPtr<int> bPtr(b);
    BlobPtr<std::string> cPtr(c1);
    BlobPtr<std::string> dPtr(d);

    std::cout << "a Test:" << std::endl;
    TestBlobFunctions(a1, 100);
    std::cout << std::endl;

    std::cout << "b Test:" << std::endl;
    TestBlobFunctions(b, 100);
    std::cout << std::endl;

    std::cout << "c Test:" << std::endl;
    TestBlobFunctions(c1, std::string("fun"));
    std::cout << std::endl;

    std::cout << "d Test:" << std::endl;
    TestBlobFunctions(d, std::string("fun"));
    std::cout << std::endl;

    std::cout << "Int Relations Test" << std::endl;
    std::cout << "Equal: " << std::endl;
    TestBlobRelations(a1, a2);
    std::cout << std::endl;
    std::cout << "Not Equal: " << std::endl;
    TestBlobRelations(a1, b);
    std::cout << std::endl;

    std::cout << "String Relations Test" << std::endl;
    std::cout << "Equal: " << std::endl;
    TestBlobRelations(c1, c2);
    std::cout << std::endl;
    std::cout << "Not Equal: " << std::endl;
    TestBlobRelations(c1, d);
    std::cout << std::endl;

    std::cout << "aPtr Test" << std::endl;
    TestBlobPtr(aPtr);
    std::cout << std::endl;

    std::cout << "bPtr Test" << std::endl;
    TestBlobPtr(bPtr);
    std::cout << std::endl;

    std::cout << "Begin and End Test: " << std::endl;
    for (BlobPtr<int> i = b.begin(); i != b.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}