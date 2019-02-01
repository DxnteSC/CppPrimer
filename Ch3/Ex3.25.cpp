#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned> v(11,0);
    unsigned grade;
    while (cin >> grade)
    {
        ++*(v.begin() + grade/10);
    }
    for (auto c: v)
    {
        cout << c << " ";
    }
    cout << endl;
}
