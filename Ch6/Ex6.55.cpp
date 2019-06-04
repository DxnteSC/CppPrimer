#include <iostream>
#include <vector>

int add(int a, int b) {
    return a+b;
}

int subtract(int a,int b) {
    return a-b;
}

int multiply(int a, int b) {
    return a*b;
}

int divide(int a,int b) {
    return a/b;
}

int main() {
    
    std::vector<int(*)(int,int)> v;
    v.push_back(add);
    v.push_back(subtract);
    v.push_back(multiply);
    v.push_back(divide);
    int a,b;
    for (auto f:v) {
        std::cout << f(8,8) << std::endl;
    }
}
