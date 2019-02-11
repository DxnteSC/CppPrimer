#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ia[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v1(begin(ia),end(ia));
    
    for (auto c: ia)
    {
        cout << c << " ";
    }
    cout << endl;
    
    for (auto c: v1)
    {
        cout << c << " ";
    }
    cout << endl;
}
