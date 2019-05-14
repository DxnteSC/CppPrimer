#include <iostream>

int main(int argc, char *argv[]) {
    
    std::string s;
    
    if (argc > 3) {
        std::cout << "Only 2 or less arguments are accepted in this program" << std::endl;
        return -1;
    } else {
        for (int i = 0; i != argc - 1; ++i) {
            s += argv[i + 1];
            s += " ";
        }
    }
    std::cout << s << std::endl;
}
