#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    decltype(s.size()) cnt = 0;
    while (cnt < s.size())
    {
        s[cnt] = 'X';
        ++cnt;
    }
    cout << s << endl;
}
