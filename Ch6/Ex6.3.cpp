#include <iostream>

using namespace std;



int factorial (int x) {
    int currVal = 1;
    for (;x>0;x--) {
        currVal *= x;
    }
    return currVal;
}

int main() {
    int i = factorial(9);
    cout << i << endl;
    
}



