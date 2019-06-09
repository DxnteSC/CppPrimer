#include "Screen.h"
#include "Window_mgr.h"

using namespace std;

int main() {
    Screen s1(1, 1, 'X');
    Screen s2(5,5,'D');
    
    Window_mgr window;
    window.addScreen(s1);
    window.addScreen(s2);
    
    for (auto i = 0; i != window.size();++i) {
        window.getScreen(i).display(cout);
        cout << '\n';
    }
    window.clear(2);
    for (auto i = 0; i != window.size();++i) {
        window.getScreen(i).display(cout);
        cout << '\n';
    }
}
