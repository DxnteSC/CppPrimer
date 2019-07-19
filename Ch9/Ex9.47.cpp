#include <iostream>
#include <string>

int main() {
    std::string numbers = "0123456789", letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string testString = "ab2c3d7R4E6";
    
    std::cout << "Using find_first_of"  << std::endl;
    std::cout << "Numbers: " << std::endl;
    
    std::string::size_type numPos = 0;
    
    while ((numPos = testString.find_first_of(numbers,numPos)) != std::string::npos) {
        std::cout << "Index: " << numPos << ", Value: " << testString[numPos] << std::endl;
        ++numPos;
    }
    
    std::cout << std::endl;
    std::cout << "Letters: " << std::endl;
    
    std::string::size_type letterPos = 0;
    
    while ((letterPos = testString.find_first_of(letters,letterPos)) != std::string::npos) {
        std::cout << "Index: " << letterPos << ", Value: " << testString[letterPos] << std::endl;
        ++letterPos;
    }
    
    std::cout << std::endl;
    std::cout << "Using find_first_not_of"  << std::endl;
    std::cout << "Numbers: " << std::endl;
    
    std::string::size_type numPos2 = 0;
    
    while ((numPos2 = testString.find_first_not_of(letters,numPos2)) != std::string::npos) {
        std::cout << "Index: " << numPos2 << ", Value: " << testString[numPos2] << std::endl;
        ++numPos2;
    }
    
    std::cout << std::endl;
    std::cout << "Letters: " << std::endl;
    
    std::string::size_type letterPos2 = 0;
    
    while ((letterPos2 = testString.find_first_not_of(numbers,letterPos2)) != std::string::npos) {
        std::cout << "Index: " << letterPos2 << ", Value: " << testString[letterPos2] << std::endl;
        ++letterPos2;
    }
}
