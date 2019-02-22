#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {0,1,2,3,4,5,6,7,8,9};
    for (vector<int>::iterator i = v1.begin(); i != v1.end(); ++i)
    {
        *i = *i % 2 !=0 ? *i * 2 : *i;
    }
    for (auto &c: v1)
    {
        cout << c << " ";
    }
    cout << endl;
}

