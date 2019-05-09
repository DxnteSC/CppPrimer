#include <iostream>

void pointerSwap(int *&i, int *&j) {
    int *temp = i;
    i = j;
    j = temp;
}

int main() {
    int i = 5, j = 10;
    int *pi = &i, *pj = &j;
    std::cout << *pi << " " << *pj << std::endl;
    pointerSwap(pi,pj);
    std::cout << *pi << " " << *pj << std::endl;
}
