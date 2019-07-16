#include <vector>
#include <iostream>

int main() {
    
    // causes an infinite loop if it hits an odd number.
    std::vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while (iter != vi.end())
        if (*iter % 2)
            iter = vi.insert(iter, *iter);
    ++iter;
}
