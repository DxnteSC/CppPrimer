#include <iostream>
#include "Chapter6.h"

using namespace std;

int fact (int x) {
    int currVal = 1;
    for (;x>0;x--) {
        currVal *= x;
    }
    return currVal;
}
