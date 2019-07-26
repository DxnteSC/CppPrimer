#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Sales_data.h"

bool compareISBN(const Sales_data& sd1, const Sales_data& sd2) {
    return sd1.isbn() < sd2.isbn();
}

int main() {
    std::vector<Sales_data> v;
    Sales_data sd;
    while (read(std::cin,sd)) {
        v.push_back(sd);
    }
    std::cout << "Before Sort: " << std::endl;
    for (const Sales_data& sd: v) {
        print(std::cout,sd);
        std::cout << std::endl;
    }
    sort(v.begin(),v.end(), [] (const Sales_data& a, const Sales_data& b) {return a.isbn() < b.isbn();});
    std::cout << std::endl;
    std::cout << "After Sort: " << std::endl;
    for (const Sales_data& sd: v) {
        print(std::cout,sd);
        std::cout << std::endl;
    }
}
