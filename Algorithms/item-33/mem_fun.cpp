#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class base
{

public:
    int x;
    base(int a) : x(a) {}
    void get() { std::cout << x << std::endl; }
};

int main()
{
    base obj_A(1);
    base obj_B(2);

    auto p = std::mem_fun(&base::get);
    p(&obj_A);
    p(&obj_B);

    auto q = std::mem_fn(&base::x);
    std::cout << q(obj_A);
    std::cout << q(obj_B);

    
    return 0;
}