#include <iostream>
#include <string>

int main()
{
    const char* c1 = "Hello, ";
    const char* c2 = "World!";
    char* cA = new char[std::strlen(c1) + std::strlen(c2) + 1];
    std::strcpy(cA,c1);
    std::strcat(cA,c2);
    std::cout << cA << std::endl;
    delete[] cA;
    
    std::string s1 = "Hello, ";
    std::string s2 = "World!";
    std::string s3 = s1 + s2;
    std::cout << s3 << std::endl;
}
