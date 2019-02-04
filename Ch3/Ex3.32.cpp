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
    cout << "ia: " << endl;
    for (auto i: ia)
    {
        cout << i << " ";
    }
    cout << endl;
    
    int ib[array_sz];
    for ( size_t j = 0; j != array_sz; ++j)
    {
        ib[j] = ia[j];
    }
    cout << "ib: " << endl;
    for (auto i: ib)
    {
        cout << i << " ";
    }
    cout << endl;

    
    vector<int> v1, v2;
    for (decltype(v1.size()) i = 0; i!= 10; ++i)
    {
        v1.push_back(i);
    }
    cout << "v1: " << endl;
    for (auto i: v1)
    {
        cout << i << " ";
    }
    cout << endl;

    v2 = v1;
    cout << "v2: " << endl;
    for (auto i: v2)
    {
        cout << i << " ";
    }
    cout << endl;

}
