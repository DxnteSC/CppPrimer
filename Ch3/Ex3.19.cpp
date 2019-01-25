#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    // Number 1, best way for this example as least amount of code.
    vector<int> v1(10,42);
    // Number 2
    vector<int> v2 = {42,42,42,42,42,42,42,42,42,42};
    // Number 3
    vector<int> v3;
    for (int i = 0; i != 10; ++i)
    {
        v3.push_back(42);
    }
}
