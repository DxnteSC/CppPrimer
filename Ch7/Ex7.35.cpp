#include <iostream>
#include <string>

typedef std::string Type;
Type initVal(); // uses string

class Exercise {
public:
    typedef double Type;
    Type setVal(Type); // uses double
    Type initVal(); // uses double

private:
    int val;
};

//use Exercise::Type Exercise::setVal
Type Exercise::setVal(Type parm) {  //String exercise, double parm
    val = parm + initVal();
    return val;
}

Exercise::Type Exercise::initVal() {
    return 0;
}

int main() {
    return 0;
}
