#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v; // create a vector<int> and fill it with
    v.reserve(10); // the values 1-10. (See Item 14 for an
    // cout << v.size();               // prints 10
    for (int i = 0; i < 10; ++i)
    { // explanation of the reserve call.)
        v.push_back(i);
    }
    v[3] = v[5] = v[9] = 99; // set 3 elements to 99
    for (int i = 0; i < 10; ++i)
    { // explanation of the reserve call.)
        std::cout << i << ":" << v[i] << "\n";
    }
    v.erase(remove(v.begin(), v.end(), 99), v.end()); // remove all elements with value 99
    // cout << v.size();

    for (int i = 0; i < 10; ++i)
    { // explanation of the reserve call.)
        std::cout << i << ":" << v[i] << "\n";
    }

    return 0;
}