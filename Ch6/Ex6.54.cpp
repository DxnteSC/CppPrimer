#include <iostream>
#include <vector>

int iRet(int a, int b) {
    std::cout << a + b << std::endl;
    return a+b;
};

int main() {
    std::vector<int(*)(int,int)> v;
    v.push_back(iRet);
    
    for (auto a: v) {
        std::cout << a(5,5) <<std::endl;
    }
}

