#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
    std::istream_iterator<int> in(std::cin);
    std::istream_iterator<int> eof;
    std::ostream_iterator<int> out(std::cout, " ");
    std::vector<int> v(in,eof);
    std::sort(v.begin(),v.end());
    std::copy(v.begin(),v.end(),out);
    std::cout << std::endl;
}
