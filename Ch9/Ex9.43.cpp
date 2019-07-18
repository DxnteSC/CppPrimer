#include <iostream>
#include <string>

void replaceVals(std::string& s, const std::string& oldVal, const std::string& newVal) {
    for (auto iter = s.begin(); iter < s.end() - oldVal.size() + 1;) {
        auto iter2 = oldVal.cbegin();
        for (auto iter3 = iter; iter2 != oldVal.cend(); ++iter2, ++iter3) {
            if (*iter2 != *iter3) {
                break;
            }
        }
        if (iter2 == oldVal.cend()) {
            std::string::size_type pos = iter - s.begin();
            s.erase(pos, oldVal.size());
            s.insert(pos, newVal);
            iter = s.begin() + pos + newVal.size();
        } else {
            ++iter;
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
