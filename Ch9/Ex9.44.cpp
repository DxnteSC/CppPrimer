#include <iostream>
#include <string>

void replaceVals(std::string& s, const std::string& oldVal, const std::string& newVal) {
    for (std::string::size_type pos = 0; pos < s.size();) {
        if (s.substr(pos,oldVal.size()) == oldVal) {
            s.replace(pos,oldVal.size(), newVal);
            pos += newVal.size();
        } else {
            ++pos;
        }
    }
}

int main() {
    std::string s = "go thru over dere, b careful tho";
    std::cout << "Before Edit: " << s << std::endl;
    replaceVals(s,"thru","through");
    replaceVals(s,"dere","there");
    replaceVals(s,"b","be");
    replaceVals(s,"tho","though");
    std::cout << "After Edit: " << s << std::endl;
}
