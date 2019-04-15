#include <iostream>

using namespace std;

int returnAbsValue (int x) {
    if (x == 0) {
        return 0;
    } else if (x < 0) {
        int absVal = 0;
        for (int i = x; i != 0; ++i) {
            absVal++;
        }
        return absVal;
    } else {
        return x;
    }
}

int main() {
    int j = returnAbsValue(-67876);
    int k = returnAbsValue(72);
    
    cout << j << " " << k << endl;
}
