#include <iostream>
#include <string>



bool containsCapitals(const std::string &s) {
    for (auto it = s.begin(); it != s.end();++it) {
        if (isupper(*it)) {
            return true;
        } else {
            return false;
        }
    }
}

void toLower(std::string &s) {
    for (auto &c: s) {
        c = std::tolower(c);
    }
}

int main() {
    // Different arguements, containsCapitals is a const string as the argumenent passed in does not need to be changed, toLower is a non-const string as the argument needs to be changed.
}
