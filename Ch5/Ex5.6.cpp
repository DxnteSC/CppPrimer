#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int g;
    cin >> g;
    cout << (g < 60 ? "Fail" : g == 100 ? "A*" : g >= 60 && g < 70 ? "D" : g >= 70 && g < 80 ? "C" : g >= 80 && g < 90 ? "B" : "A") << endl;
}
