#include <iostream>
#include <list>

int main()
{
    std::list<int> L1 = {1, 2, 3, 4};

    for (const auto& itr : L1)
        std::cout << itr << std::endl;

    std::cout << "\nfront " << L1.front();
    std::cout << "\nback " << L1.back();

    return 0;
}