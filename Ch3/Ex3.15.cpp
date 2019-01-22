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
    for (auto c: v1)
    {
        cout << c << endl;
    }
    return 0;
}
