#include <algorithm>
#include <iostream>
#include <vector>

class isEqual
{
public:
    isEqual(const int &a) : i(a) {}
    bool operator()(int j)
    {
        return i == j;
    }

private:
    int i;
};

int main()
{
    std::vector<int> v = {1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1};
    std::replace_if(v.begin(), v.end(), isEqual(1), 0);
    for (const int i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}