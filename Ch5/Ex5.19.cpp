#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    do {
        if (s1 > s2) {
            cout << s2 << " is less than " << s1 << endl;
        } else if (s1 < s2) {
            cout << s1 << " is less than " << s2 << endl;
        } else {
            cout << "Strings are equal" << endl;
        }
    } while (cin >> s1 >> s2);
}
