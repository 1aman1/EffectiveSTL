#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    std::vector<char> chars{'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    chars.erase(std::remove(chars.begin(), chars.end(), 'a'),
                chars.end());

    for (const auto &i : chars)
        std::cout << i;

    return 0;
}