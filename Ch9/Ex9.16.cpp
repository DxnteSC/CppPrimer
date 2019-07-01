#include <iostream>
#include <vector>
#include <list>

bool compCheck(std::list<int> l1, std::vector<int> v1) {
    std::vector<int> temp(l1.begin(),l1.end());
    if (temp == v1) {
        return true;
    }
    return false;
}

int main() {
    
    std::vector<int> vTest = {0,1,2,3,4};
    
    std::list<int> a = {0,1,2,3,4};
    std::list<int> b = {0,1,2,3};
    std::list<int> c = {0,1,2,3,4,5};
    std::list<int> d = {0,2,1,3,4};
    
    std::vector<std::list<int>> lContainer = {a,b,c,d};
    for (auto i: lContainer) {
        std::cout << compCheck(i,vTest) << std::endl;
    }
}
