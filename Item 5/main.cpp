#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    int numValues = 10;

    int data[numValues];
    std::vector<int> myvec;

    std::iota(data, data + numValues, 1);

    myvec.insert(myvec.begin(), data, data + numValues);

    for (const auto &i : myvec)
        std::cout << i << " ";

    std::cout << std::endl;

    // add assign function

    return 0;
}