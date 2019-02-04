#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const int array_sz = 10;
    int ia[array_sz];
    for ( size_t i = 0; i != array_sz; ++i)
    {
        ia[i] = i;
    }
    for (auto i: ia)
    {
        cout << i << endl;
    }
}
