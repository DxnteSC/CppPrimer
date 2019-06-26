#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cerr << "Too many arguments given" << std::endl;
        return -1;
    }
    if (argc < 2) {
        std::cerr << "Provide file to be read" << std::endl;
        return -2;
    }
    std::vector<std::string> str_vec;
    std::ifstream read(argv[1]);
    std::string word, line;
    if (read) {
        while (getline(read,line)) {
            str_vec.push_back(line);
        }
    } else {
        std::cerr << "Error opening file" <<std::endl;
        return -3;
    }
    for (std::string& s: str_vec) {
        std::istringstream words(s);
        while (words >> word) {
            std::cout << word << std::endl;
        }
    }
}
