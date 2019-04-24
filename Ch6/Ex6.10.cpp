#include <iostream>

using namespace std;

void swapInts (int *p, int*q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main() {
    int i = 0, j = 5;
    int *pi = &i, *pj = &j;
    cout << i << " " << *pi << " " << j << " " << *pj << endl;
    swapInts(&i, &j);
    cout << i << " " << *pi << " " << j << " " << *pj << endl;
}
