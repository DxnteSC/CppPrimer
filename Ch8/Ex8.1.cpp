#include <iostream>
#include <string>

std::istream& read(std::istream& is) {
    std::istream::iostate state = is.rdstate();
    std::string s;
    while(is >> s) {
        std::cout << s << " ";
        if (state & is.eofbit) {
            std::cout << std::endl;
            is.clear();
            return is;
        }
    }
    is.clear();
    return is;
}

int main() {
    read(std::cin);
}
