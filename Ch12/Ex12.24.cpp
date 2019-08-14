#include <iostream>
#include <string>

int main()
{


    std::cout << "Input string length: ";
    size_t sz;
    std::cin >> sz;
    std::cin.ignore(); // ignore one char after the length number
    char *arr = new char[sz + 1];
    std::cin.get(arr, sz + 1);
    std::cout << "The input string is: " << arr << std::endl;
        
    // If the input string is longer than the size of the array, then all input characters whose positions are after the array size will be ignored.
    
}
