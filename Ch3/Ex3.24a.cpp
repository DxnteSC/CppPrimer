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
        for (auto i = v1.cbegin(); i != v1.cend(); i+=2)
        {
            cout << *i + *(i+1) << endl;
        }
    }
    else
    {
        for (auto i = v1.cbegin(); i <= v1.cend(); i+=2)
        {
            if (i == v1.cend())
            {
                cout << *i << endl;
            }
            else
            {
                cout << *i + *(i+1) << endl;
            }
        }
    }
}
