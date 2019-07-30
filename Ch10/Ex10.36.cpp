#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::vector<int> v = {3,2,5,2,4,5,1,4,0,4,2,4,5,6,2,4,1,3,5,2,1,0,5,3,1,4,5,6,7,8,9,7,6,5,4,3,4,5};
    auto it = std::find(v.crbegin(), v.crend(),0);
    std::cout << "The last 0 is at position " << (it.base() - v.begin()) << std::endl;
}
