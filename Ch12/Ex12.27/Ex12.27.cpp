#include "Query.h"

void runQueries(std::ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile);  //  store the file and build the query map
    // iterate with the user: prompt for a word to find and print results
    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(std::cin >> s) || s == "q") break;
        // run the query and print the results
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main (int argc, char* argv[])
{
    if (argc != 2)
    {
        if (argc == 1)
        {
            std::cerr << "Missing input file" << std::endl;
            return -1;
        }
        if (argc > 2)
        {
            std::cerr << "Too many files" << std::endl;
            return -2;
        }
    }
    
    std::ifstream input(argv[1]);
    if (!input)
    {
        std::cerr << "Input file invalid" << std::endl;
        return -3;
    }
    
    runQueries(input);
}
