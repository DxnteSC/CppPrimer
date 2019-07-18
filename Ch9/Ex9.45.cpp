#include <iostream>
#include <string>

std::string addPrefixAndSuffix(const std::string& name, const std::string& prefix, const std::string& sufffix) {
    std::string newString = name;
    std::string newPrefix = prefix + " ";
    newString.insert(newString.begin(),newPrefix.begin(),newPrefix.end());
    newString.append(" " + sufffix);
    return newString;
}

int main() {
    std::cout << addPrefixAndSuffix("Dante", "Mr","Jr.") << std::endl;
}
