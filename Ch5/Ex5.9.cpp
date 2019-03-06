#include <iostream>
#include <string>

using namespace std;

int main()
{
    char ch;
    int vowelCnt;
    
    while (cin >> ch)
    {
        if (ch == 'a')
            ++vowelCnt;
        if (ch == 'e')
            ++vowelCnt;
        if (ch == 'i')
            ++vowelCnt;
        if (ch == 'o')
            ++vowelCnt;
        if (ch == 'u')
            ++vowelCnt;
    }
    
    cout << "Number of Vowels: " << vowelCnt << endl;
}
