#include <iostream>
#include <vector>
#include <algorithm>

struct Widget
{
    int i;
    float f;
    Widget(int i, float f) : i(i), f(f) {}
};

void print(Widget w) { std::cout << w.i << " "; }

int main()
{
    Widget obj1(1, 1.1);
    Widget obj2(2, 2.2);

    std::vector<Widget> vw;

    vw.push_back(obj2);
    vw.push_back(obj1);

    std::for_each(vw.begin(), vw.end(), print);

    // throws errors
    // std::sort(vw.begin(), vw.end());

    std::cout << "\n";

    return 0;
}