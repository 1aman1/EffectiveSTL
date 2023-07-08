#include <iostream>
#include <list>

int main()
{
    std::list<int> list = {1, 2, 3, 4};

    for (const auto &itr : list)
        std::cout << itr << ":";
    std::cout << std::endl;

    list.remove(2);

    for (const auto &itr : list)
        std::cout << itr << ":";
    std::cout << std::endl;

    return 0;
}