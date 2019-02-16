#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int i;
    vector<int> ivec;
    
    while (cin >> i && i != 42)
    {
        ivec.push_back(i);
    }
    
    cout << endl;
    
    for (auto &c: ivec)
    {
        cout << c << " ";
    }
    
    cout << endl;
}
