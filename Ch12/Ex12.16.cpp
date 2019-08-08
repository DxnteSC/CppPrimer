#include <iostream>
#include <memory>

int main()
{
    /*
     
     --- Assign ---
     
     std::unique_ptr<int> p(new int(5));
     std::unique_ptr<int> p2;
     p2 = p;
     
     error: object of type 'std::__1::unique_ptr<int,
     std::__1::default_delete<int> >' cannot be assigned because its copy assignment operator is implicitly deleted
     
     ---- Copy ----
     
     std::unique_ptr<int> p(new int(5));
     std::unique_ptr<int> p2(p);
     
     error: call to implicitly-deleted copy constructor of 'std::unique_ptr<int>'
     
     */
}
