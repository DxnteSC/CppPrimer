#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    int total = std::accumulate(v.cbegin(),v.cend(),0);
    std::cout << total << std::endl;
}
