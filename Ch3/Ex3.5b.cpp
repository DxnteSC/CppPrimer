#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    if (cin >> s1)
    {
        while (cin >> s2)
        {
            s1 = s1 + " " + s2;
        }
        cout << s1 << endl;
        return 0;
    }
}
