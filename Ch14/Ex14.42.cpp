#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<int> v = {5, 6, 7, 8, 9, 1025, 1026, 1027, 1028, 1029};
    std::vector<std::string> s = {"pooh", "pooh", "pooh", "pooh", "not pooh", "pooh", "Dante"};
    int i = std::count_if(v.begin(), v.end(), std::bind(std::greater<int>(), std::placeholders::_1, 1024));
    std::vector<std::string>::iterator it = std::find_if_not(s.begin(), s.end(), std::bind(std::equal_to<std::string>(), std::placeholders::_1, "pooh"));
    std::vector<int> v2;
    std::transform(v.begin(), v.end(), std::back_inserter(v2), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
    std::cout << "The number of elements above 1024 is: " << i << std::endl;
    std::cout << "The first string not equal to pooh is: " << *it << std::endl;
    std::cout << "The elements of v2 are: {";
    for (int i : v2)
    {
        std::cout << i << ", ";
    }
    std::cout << "}" << std::endl;
}