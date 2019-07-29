#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
    std::ifstream input("input");
    std::istream_iterator<std::string> reader(input);
    std::istream_iterator<std::string> eof;
    std::ostream_iterator<std::string> out(std::cout, " ");
    std::vector<std::string> v;
    while (reader != eof) {
        v.push_back(*reader++);
    }
    for (auto s: v) {
        out = s;
    }
    std::cout << std::endl;
}
