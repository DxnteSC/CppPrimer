#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int g;
    if (cin >> g)
    {
        if (g < 60)
        {
            cout << "Fail" << endl;
        }
        else if (g == 100)
        {
            cout << "A*" << endl;
        }
        else
        {
            if (g >= 60 && g < 70)
            {
                cout << "D";
            }
            else if (g >= 70 && g < 80)
            {
                cout << "C";
            }
            else if (g >= 80 && g < 90)
            {
                cout << "B";
            }
            else if (g >=90 && g <100)
            {
                cout << "A";
            }
            
            if (g % 10 < 3)
            {
                cout << "-" << endl;
            }
            else if (g%10 > 7)
            {
                cout << "+" << endl;
            }
            else
            {
                cout << endl;
            }
        }
    }
}
