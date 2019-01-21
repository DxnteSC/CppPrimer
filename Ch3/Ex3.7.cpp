#include <iostream>
#include <string>

using namespace std;

// Nothing happens

int main()
{
    string s;
    cin >> s;
    cout << s << endl;
    for (auto c: s)
    {
        c = 'X';
    }
    cout << s << endl;
}
