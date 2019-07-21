#include <iostream>
#include <vector>
#include <string>

int main() {
    
    std::vector<std::string> vInts = {"1","2","3","4","5"};
    std::vector<std::string> vFloats = {"1.2", "2.4", "3.6"};
    int intTotal = 0;
    float floatTotal = 0;
    for (auto i = vInts.begin(); i != vInts.end(); ++i) {
        intTotal += stoi(*i);
    }
    for (auto i = vFloats.begin(); i != vFloats.end(); ++i) {
        floatTotal += stof(*i);
    }
    std::cout << "(Int) Sum of all elements in the vector is: " << intTotal << std::endl;
    std::cout << "(Float) Sum of all elements in the vector is: " << floatTotal << std::endl;
}
