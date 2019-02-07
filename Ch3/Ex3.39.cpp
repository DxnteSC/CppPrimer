#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s1 = "Hello";
    string s2 = "Hello";
    
    if (s1 == s2)
    {
        cout << "Strings are equal" << endl;
    }
    else
    {
        cout << "Strings aren't equal" << endl;
    }
    
    char cc1[] = {'h','e','l','l','o'};
    char cc2[] = {'h','e','l','l','o'};
    
    if (strcmp(cc1,cc2) != 0)
    {
        cout << "Strings aren't equal" << endl;
    }
    else
    {
        cout << "Strings are equal" << endl;
    }
}
