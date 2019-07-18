#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<char> v = {'H', 'i'};
    std::string s(v.cbegin(),v.cend());
    std::cout << s << std::endl;
}
