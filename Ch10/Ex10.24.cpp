#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>


bool checkSize (const std::string& s, int i) {
    return i > s.size();
}


int main() {
    std::string s = "ABCDEFGHIJK";
    std::vector<int> v = {67, 80, 9, 98, 38, 31, 36, 20, 54, 48};
    std::sort(v.begin(),v.end(), [] (const int a, const int b) {return a < b;});
    auto val = std::find_if(v.begin(),v.end(),std::bind(checkSize,s,std::placeholders::_1));
    std::cout << "The first value in the vector with size larger than " << s.size() << " is " << *val << std::endl;
}
