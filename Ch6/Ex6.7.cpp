#include <iostream>

using namespace std;

int counter() {
    static int ctr = 0;
    return ctr++;
}
