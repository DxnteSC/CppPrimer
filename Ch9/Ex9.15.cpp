#include <iostream>
#include <vector>

bool vecCheck(std::vector<int> v1, std::vector<int> v2) {
    if (v1 == v2) {
        return true;
    }
    return false;
}

int main() {
    
    std::vector<int> vTest = {0,1,2,3,4};
    
    std::vector<int> a = {0,1,2,3,4};
    std::vector<int> b = {0,1,2,3};
    std::vector<int> c = {0,1,2,3,4,5};
    std::vector<int> d = {0,2,1,3,4};
    
    std::vector<std::vector<int>> vContainer = {a,b,c,d};
    for (auto i: vContainer) {
        std::cout << vecCheck(vTest,i) << std::endl;
    }
}
