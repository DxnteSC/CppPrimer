#include <fstream>
#include <iostream>
#include <iterator>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        if (argc == 1) {
            std::cerr << "Missing input and 2 output files" << std::endl;
            return -1;
        } else if (argc == 2) {
            std::cerr << "Missing 2 output files" << std::endl;
            return -2;
        } else if (argc == 3) {
            std::cerr << "Missing an ouput file" << std::endl;
            return -3;
        } else {
            std::cerr << "Too many files given" << std::endl;
            return -4;
        }
    }
    
    std::ifstream input(argv[1]);
    std::ofstream oddOutput(argv[2]);
    std::ofstream evenOutput(argv[3]);
    
    if (!input) {
        std::cerr << "Error opening file" << std::endl;
        return -5;
    }
    std::istream_iterator<int> intIn(input);
    std::istream_iterator<int> eof;
    std::ostream_iterator<int> oddOutputIter(oddOutput, " ");
    std::ostream_iterator<int> evenOutputIter(evenOutput, "\n");
    while (intIn != eof) {
        if (*intIn % 2) {
            oddOutputIter = *intIn++;
        } else {
            evenOutputIter = *intIn++;
        }
    }
}
