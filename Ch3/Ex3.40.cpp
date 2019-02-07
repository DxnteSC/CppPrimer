#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const char c1[] = "Hello, there";
    const char c2[] = "Dante.";
    char c3[20];
    strcpy(c3, c1);
    strcat(c3, " ");
    strcat(c3,c2);
    
    cout << c3 << endl;
}
