#include <iostream>

bool str_subrange(const std::string &str1, const std::string &str2) {
    if (str1.size() == str2.size()) {
        return str1 == str2;
    }
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();
    for (decltype(size) i = 0; i != size; ++i) {
        if (str1[i] != str2[i]) {
            return; // ERROR: non-void function should return a value
        }
    }
    // WARNING: control may reach end of non-void function
}

int main() {
    
    std::cout << str_subrange("Hello","Hello") << std::endl;
    
}
