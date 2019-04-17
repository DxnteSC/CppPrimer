#include <iostream>

using namespace std;

void factorial2() {
    int x, currVal = 1;
    cout << "Enter a number: " << endl;
    cin >> x;
    for (int i = x;i>0;i--) {
        currVal *= i;
    }
    cout << "The factorial of " << x << " is " << currVal << endl;
}

int main() {
    factorial2();
}
