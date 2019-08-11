#include <fstream>
#include <iostream>

#include "StrBlob.h"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        if (argc == 1)
        {
            std::cerr << "Missing an input file" << std::endl;
            return -1;
        }
        else
        {
            std::cerr << "Too many files provided" << std::endl;
            return -2;
        }
    }
    
    std::ifstream input(argv[1]);
    if (!input)
    {
        std::cerr << "Input file not valid" << std::endl;
        return -3;
    }
    
    std::string word;
    StrBlob alpha;
    while (std::getline(input, word))
    {
        alpha.push_back(word);
    }
   
    StrBlobPtr alphaPtr(alpha);
    auto alphaBeg = alpha.begin();
    std::cout << alphaBeg.deref() << std::endl;
    alphaBeg.incr();
    std::cout << alphaBeg.deref() << std::endl;
    /* while (alphaBeg != alpha.end())
    {
        std::cout << alphaBeg.deref() << std::endl;
        alphaBeg.incr();
    } */
    // Can't compile as != operator not defined
    return 0;
}
