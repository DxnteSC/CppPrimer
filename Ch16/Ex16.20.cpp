#include <iostream>
#include <vector>

template <typename T>
void print(const T &container)
{
    // Doesn't work?
    // for (typename T::iterator b = container.begin(); b != container.end(); b++)
    // {
    //     std::cout << *b << " ";
    // }
    for (typename T::const_iterator b = container.cbegin(); b != container.cend(); b++)
    {
        std::cout << *b << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> iVec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::string> sVec = {"hi", "hello", "hey", "yo"};
    print(iVec);
    print(sVec);
}