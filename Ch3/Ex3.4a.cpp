#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == s2)
    {
        cout << "Strings are equal" << endl;
        return 0;
    }
    else if (s1 > s2)
    {
        cout << s2 + " comes before " + s1 << endl;
        return 0;
    }
    else
    {
        cout << s1 + " comes before " + s2 << endl;
        return 0;

    }
}
