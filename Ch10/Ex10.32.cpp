#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

#include "Sales_item.h"

bool compareISBN (const Sales_item& a, const Sales_item& b) {
    return a.isbn() < b.isbn();
}

int main()
{
    std::istream_iterator<Sales_item> input(std::cin);
    std::istream_iterator<Sales_item> eof;
    std::ostream_iterator<Sales_item> output(std::cout, "\n");
    std::vector<Sales_item> vSI(input,eof);
    std::sort(vSI.begin(),vSI.end(),compareISBN);
    for (auto bg = vSI.begin(), diff = bg; bg != vSI.end();bg = diff) {
        diff = std::find_if(bg, vSI.end(), [bg] (const Sales_item& a) {return a.isbn() != bg -> isbn();});
        output = std::accumulate(bg, diff, Sales_item(bg -> isbn()));
    }
}
