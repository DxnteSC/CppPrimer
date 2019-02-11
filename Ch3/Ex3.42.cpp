#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    for (int i = 0; i!=10;++i)
    {
        v1.push_back(i);
    }
    int ia[10];
    for (int i = 0; i != v1.size();++i)
    {
        ia[i] = v1[i];
    }
    
    for (auto c: v1)
    {
        cout << c << " ";
    }
    cout << endl;
    
    for (auto c: ia)
    {
        cout << c << " ";
    }
    cout << endl;
}
