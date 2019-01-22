#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    int i;
    while (cin >> i)
    {
        v1.push_back(i);
    }
    for (auto c: v1)
    {
        cout << c << endl;
    }
    return 0;
}
