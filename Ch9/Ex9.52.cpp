#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string str = "Hi there, (hi), how are you, (I'm good), that's good";
    std::stack<char> stk;
    for (const auto &c : str) {
        if (c == ')') {
            std::string s;
            while (!stk.empty() && stk.top() != '(') {
                s += stk.top();
                stk.pop();
            }
            if (stk.empty()) {
                std::cerr << "Error: Missing parenthesis pair in: "
                << str << std::endl;
            }
            stk.pop();  // pops `(`
            for (const auto &e : s)  // pushes result to stk
                stk.push(e);
        } else {
            stk.push(c);
        }
    }
    while (!stk.empty()) {
        char c = stk.top();
        std::cout << c << " ";
        stk.pop();
    }
    std::cout << std::endl;
}
