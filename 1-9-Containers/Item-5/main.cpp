#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<int> v1 = {1, 2, 3, 4};
    std::vector<int> v2 = {10, 20, 30, 40};

    for (const auto &i : v1)
        std::cout << i << " ";
    std::cout << std::endl;

    v1.assign(v2.begin() + v2.size() / 2, v2.end());

    for (const auto &i : v1)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}