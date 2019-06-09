#include <iostream>

class x;
class y;

class x {
    y* yPtr;
}

class y {
    x xObj;
}
