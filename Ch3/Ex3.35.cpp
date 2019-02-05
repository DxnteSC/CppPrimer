#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    for (auto i: arr)
    {
        cout << i << endl;
    }
    cout << endl;
    for (int *b = begin(arr),  *e = end(arr); b != e; ++b)
    {
        *b = 0;
    }
    for (auto i : arr)
    {
        cout << i << endl;
    }
}
