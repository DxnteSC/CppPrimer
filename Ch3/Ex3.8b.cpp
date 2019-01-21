#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    for (decltype(s.size()) i = 0; i < s.size(); ++i)
    {
        s[i] = 'X';
    }
    cout << s << endl;
}
