#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int ia[] = {0,1,2,3,4,5};
    int ib[] = {0,1,2,3,4,5};
    
    int *ba = begin(ia), *ea = end(ia), *bb = begin(ib), *eb = end(ib);
    if ((ea-ba) != (eb-bb))
    {
        cout << "Arrays not equal" << endl;
    }
    else
    {
        while ((ba != ea) && (bb != eb))
        {
            if (*ba != *bb)
            {
                cout << "Arrays not equal" << endl;
                return -1;
            }
            else
            {
                ++ba;
                ++bb;
            }
        }
        cout << "Arrays are equal" << endl;
    }
    
    vector<int> v1 = {0,1,2,3,4,5};
    vector<int> v2 = {0,1,2,3,4,5};
    
    if (v1 == v2)
    {
        cout << "Vectors are equal" << endl;
    }
    else
    {
        cout << "Vectors not equal" << endl;
    }
}
