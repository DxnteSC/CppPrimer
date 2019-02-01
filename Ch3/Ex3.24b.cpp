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
        for (auto i = v1.cbegin(), j = v1.cend() - 1; i < (v1.begin() + v1.size()/2); ++i, --j)
        {
            cout << *i + *j << endl;
        }
    }
    else
    {
        for (auto i = v1.cbegin(), j = v1.cend() - 1; i <= (v1.begin() + v1.size()/2); ++i, --j)
        {
            if (i == (v1.begin() + v1.size()/2))
            {
                cout << *i << endl;
            }
            else
            {
                cout << *i + *j << endl;
            }
        }
    }
}

