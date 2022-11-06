#include <iostream>
#include <vector>
#include <algorithm>

// after swap verif

int main()
{
    std::vector<int> vec{1, 2, 3};

    auto itr = std::find(vec.begin(), vec.end(), 2);

    std::cout << *itr;

    std::vector<int>(vec).swap(vec);

    std::cout << *itr;

    return 0;
}