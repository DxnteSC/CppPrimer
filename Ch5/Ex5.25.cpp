#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int a,b;
    try {
        cin >> a >> b;
        if (b == 0) {
            throw runtime_error("Can't divide by 0");
        }
        cout << "The result of " << a << " divided by " << b << " is " << a/b << endl;
    } catch (runtime_error err) {
        do {
            cout << "Input another number" << endl;
            cin >> b;
        } while (b == 0);
        cout << "The result of " << a << " divided by " << b << " is " << a/b << endl;
    }
    return 0;
}
