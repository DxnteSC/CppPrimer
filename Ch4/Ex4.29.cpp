#include <iostream>

using namespace std;

int main()
{
    int x[10];
    int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl; // prediction 10: actual 10 because returns size of the array.
    cout << sizeof(p)/sizeof(*p) << endl; // prediction 1: actual 2 because size of a pointer, i.e 8 bytes and the size of whtat p points to, i.e. x[0] which is an int, so 4 bytes.
}
