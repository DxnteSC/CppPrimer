#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2(10);
    vector<int> v3(10, 42);
    vector<int> v4{10};
    vector<int> v5{10, 42};
    vector<string> v6{10};
    vector<string> v7{10, "hi"};
    
    cout << "v1: " << endl;
    cout << "size: " << v1.size() << ". Contents: empty" << endl;
    cout << "v2: " << endl;
    cout << "size: " << v2.size() << endl;
    for (auto i = v2.cbegin(); i != v2.cend();++i)
    {
        cout << *i << endl;
    }
    cout << "v3: " << endl;
    cout << "size: " << v3.size() << endl;
    for (auto i = v3.cbegin(); i != v3.cend();++i)
    {
        cout << *i << endl;
    }
    cout << "v4: " << endl;
    cout << "size: " << v4.size() << endl;
    for (auto i = v4.cbegin(); i != v4.cend();++i)
    {
        cout << *i << endl;
    }
    cout << "v5: " << endl;
    cout << "size: " << v5.size() << endl;
    for (auto i = v5.cbegin(); i != v5.cend();++i)
    {
        cout << *i << endl;
    }
    cout << "v6: " << endl;
    cout << "size: " << v6.size() << endl;
    for (auto i = v6.cbegin(); i != v6.cend();++i)
    {
        cout << *i << endl;
    }
    cout << "v7: " << endl;
    cout << "size: " << v7.size() << endl;
    for (auto i = v7.cbegin(); i != v7.cend();++i)
    {
        cout << *i << endl;
    }
}
