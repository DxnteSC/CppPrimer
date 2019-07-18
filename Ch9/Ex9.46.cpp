#include <iostream>
#include <string>

std::string addPrefixAndSuffix(const std::string& name, const std::string& prefix, const std::string& sufffix) {
    std::string newString = name;
    std::string newPrefix = prefix + " ";
    newString.insert(0,newPrefix);
    newString.insert(newString.size()," " + sufffix);
    return newString;
}

int main() {
    std::cout << addPrefixAndSuffix("Dante", "Mr","Jr.") << std::endl;
}
