#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size())
    {
        cout << "Strings are equal" << endl;
        return 0;
    }
    else if (s1.size() > s2.size())
    {
        cout << s1 + " is larger than " + s2 << endl;
        return 0;
    }
    else
    {
        cout << s1 + " is smaller than " + s2 << endl;
        return 0;

    }
}
