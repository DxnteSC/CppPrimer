#include <iostream>
#include <forward_list>
#include <string>

void placeString (std::forward_list<std::string>& fList, const std::string& firstString, const std::string& secondString) {
    auto beforeCurr = fList.before_begin();
    auto curr = fList.begin();
    auto end = fList.end();
    while (curr != fList.end()) {
        if (*curr == firstString) {
            fList.insert_after(curr,secondString);
            return;
        } else {
            beforeCurr = curr;
            ++curr;
            if (curr == fList.end()) {
                fList.insert_after(beforeCurr, secondString);
            }
        }
    }
}

int main() {
    std::forward_list<std::string> f = {"Hello", "How", "Are", "You"};
    std::cout << "Before function call: ";
    for (auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    placeString(f,"Hello","User,");
    std::cout << "After function call: ";
    for (auto c: f) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
}
