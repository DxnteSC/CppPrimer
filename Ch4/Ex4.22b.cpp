#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int grade;
    cin >> grade;
    if (grade > 90)
    {
        cout << "High Pass" << endl;
    }
    else if (grade >= 60 && grade <= 75)
    {
        cout << "Low Pass" << endl;
    }
    else if (grade < 60)
    {
        cout << "Fail" << endl;
    }
    else
    {
        cout << "Pass" << endl;
    }
}
