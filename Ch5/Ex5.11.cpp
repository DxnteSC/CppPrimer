#include <iostream>


using namespace std;

int main()
{
    char ch;
    int vowelCnt = 0, otherCnt = 0, blankCnt = 0, tabCnt = 0, newlineCnt = 0;
    
    while (cin.get(ch)) // get.ch() omits whitespace characters.
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
            case '\n':
                ++newlineCnt;
                break;
            case '\t':
                ++tabCnt;
                break;
            case ' ':
                ++blankCnt;
                break;
            default:
                ++otherCnt;
                break;
        }
    }
    
    cout << "Number of Vowels: " << vowelCnt << endl;
    cout << "Number of Tabs: " << tabCnt << endl;
    cout << "Number of Spaces: " << blankCnt << endl;
    cout << "Number of Newlines: " << newlineCnt << endl;
    cout << "Number of Others: " << otherCnt << endl;
}
