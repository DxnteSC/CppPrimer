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
    if (v1.size() % 2 ==0)
    {
        for (auto i = 0; i < v1.size();i+=2)
        {
            cout << v1[i] + v1[i+1] << endl;
        }
    }
    else
    {
        for (auto i = 0; i < v1.size(); i+=2)
        {
            if ((i+1) == v1.size())
            {
                cout << v1[i] << endl;
            }
            else
            {
                cout << v1[i] + v1[i+1] << endl;
            }
        }
    }
}
