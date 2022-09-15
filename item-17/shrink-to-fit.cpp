#include <iostream>

#include <vector>

int main()
{
    std::vector<int> vec;

    std::cout << vec.capacity() << std::endl;

    vec.resize(10);

    std::cout << vec.capacity() << std::endl;

    for (int i = 1; i < 5; ++i)
    {
        vec.push_back(i);
    }

    std::cout << vec.capacity() << std::endl;

    /***/
    std::vector<int>(vec).swap(vec);

    std::cout << vec.capacity() << std::endl;

    //
    std::cout << __FILE__ << std::endl;
    
    std::string S;
    S = "qwertyuiop[ qwertyuiop wertyuiop";

    std::cout << S.capacity() << std::endl;

    std::string(S).swap(S);

    std::cout << S.capacity() << std::endl;

    return 0;
}