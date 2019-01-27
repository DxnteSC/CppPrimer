#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    int i;
    
    while(cin >> i)
    {
        v1.push_back(i);
    }
    
    if (v1.size() % 2 == 0)
    {
        for (decltype(v1.size()) i = 0, j = v1.size() - 1; i < (v1.size()/2); ++i, j--)
        {
            cout << v1[i] + v1[j] << endl;
        }
    }
    else
    {
        for (decltype(v1.size()) i = 0, j = v1.size() - 1; i < (v1.size()/2) + 1; ++i, j--)
        {
            if (i == (v1.size()/2))
            {
                cout << v1[i] << endl;
            }
            else
            {
                 cout << v1[i] + v1[j] << endl;
            }
        }
    }
}
