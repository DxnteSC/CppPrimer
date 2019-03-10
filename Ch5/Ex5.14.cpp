#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s,x;
    int cnt, total;
    
    while (cin >> s)
    {
        string d;
        while (cin >> d)
        {
            if (s == d)
            {
                cnt += 1;
            }
            else
            {
                if (cnt > total)
                {
                    x = s;
                    total = cnt;
                    s = d;
                }
                else
                {
                    s = d;
                    cnt = 1;
                }
            }
        }
    }
    cout << "The word that occurs the most is " << x << " it occurs " << total << " times." << endl;
}
