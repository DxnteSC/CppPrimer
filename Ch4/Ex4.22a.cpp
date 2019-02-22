#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int grade;
    cin >> grade;
    string finalgrade = (grade > 90) ? "High Pass" : (grade >= 60 && grade <= 75) ? "Low Pass" : (grade < 60) ? "Fail" : "Pass";
    cout << finalgrade << endl;
}
