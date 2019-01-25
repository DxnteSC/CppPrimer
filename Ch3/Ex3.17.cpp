#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> v1;
    string s;
    
    while (cin >> s)
    {
        v1.push_back(s);
    }
    for (auto &i: v1)
    {
        for (auto &c: i)
        {
            c = toupper(c);
        }
    }
    for (auto i = 0; i < v1.size(); ++i)
    {
        cout << v1[i] << " ";
        if ((i + 1) % 8 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
