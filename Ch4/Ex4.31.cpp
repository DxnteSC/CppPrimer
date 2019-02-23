#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec = {0,1,2,3,4,5,6,7,8,9};
    vector<int>::size_type cnt = ivec.size();
    for (vector<int>::size_type ix = 0; ix != ivec.size(); ix++, cnt--)
    {
        ivec[ix] = cnt;
    }
    for (auto c: ivec)
    {
        cout << c << " ";
    }
    cout << endl;
}

// Used prefix increment as the original value of the incremented size_type is not needed, therefore performance is increased with prefix incrementation, with postfix no changes are needed to the actual program.
