#include <iostream>

template <typename T> int compare(const T& t1, const T& t2)
{
    if (t1 < t2) return -1;
    else if (t2 < t1) return 1;
    else return 0;
}

int main()
{
    int result = compare(5,3);
    int result2 = compare(3,5);
    int result3 = compare(5,5);
    std::cout << result << std::endl;
    std::cout << result2 << std::endl;
    std::cout << result3 << std::endl;
}