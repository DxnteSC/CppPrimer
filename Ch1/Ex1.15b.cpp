#include <iostream>

int main()
{
    int v1 = 0, v2 = 2;
    std::cin >> v >> v2; // error uses 'v' instead of 'v1'
    //error 'cout' not defined, shoudl be std::cout
    cout << v1 + v2 << std::endl;
    return 0;
}
