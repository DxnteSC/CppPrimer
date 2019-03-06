#include <iostream>

using namespace std;

int main()
{
    char ch;
    int vowelCnt;
    
    while (cin >> ch)
    {
     
        switch (ch)
        {
            case 'a': case 'A':
                ++vowelCnt;
                break;
            case 'e': case 'E':
                ++vowelCnt;
                break;
            case 'i': case 'I':
                ++vowelCnt;
                break;
            case 'o': case 'O':
                ++vowelCnt;
                break;
            case 'u': case 'U':
                ++vowelCnt;
                break;
            default:
                break;
        }
        
    }
    
    cout << "Number of Vowels: " << vowelCnt << endl;

}
