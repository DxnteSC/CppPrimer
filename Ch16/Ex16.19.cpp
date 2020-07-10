#include <iostream>
#include <vector>

template <typename T>
void print(const T &container)
{
    for (typename T::size_type i = 0; i != container.size(); i++)
    {
        std::cout << container[i] << " ";
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