#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1,s2;
    bool notRepeated = true;
    
    while (cin >> s1) {
        if (islower(s1[0])) {
            s2 = s1;
            continue;
        }
        
        if (s1 == s2) {
            cout << "Repeated word: " << s1 << endl;
            notRepeated = false;
            break;
        } else {
            s2 = s1;
        }
    }
    
    if (notRepeated) {
        cout << "No word repeated" << endl;
    }
}
