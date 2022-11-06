#include <iostream>

#include <vector>

int main()
{
    std::vector<int> vector;

    std::cout << vector.capacity() << std::endl;

    vector.resize(10);

    std::cout << vector.capacity() << std::endl;

    for (int i = 1; i < 5; ++i)
    {
        vector.push_back(i);
    }

    std::cout << vector.capacity() << std::endl;

    /***/
    std::vector<int>(vector).swap(vector);

    std::cout << vector.capacity() << std::endl;

    //
    std::cout << __FILE__ << std::endl;
    
    std::string S;
    S = "qwertyuiop[ qwertyuiop wertyuiop";

    std::cout << S.capacity() << std::endl;

    std::string(S).swap(S);

    std::cout << S.capacity() << std::endl;

    return 0;
}