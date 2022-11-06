#include <iostream>
#include <algorithm>
#include <vector>

struct Widget
{
    int data;
    Widget() { data; };
    Widget(int data) : data(data){};

    friend void
    operator<<(std::ostream &output, const Widget &obj)
    {
        output << obj.data;
    }
};

bool qualityCompare(const Widget &lhs, const Widget &rhs)
{
    return lhs.data > rhs.data;
}

int main()
{
    constexpr int SIZE = 10;
    std::vector<Widget> widgets;

    for (int i = 0; i < SIZE; ++i)
    {
        widgets.push_back({i});
        std::cout << widgets[i];
    }
    std::cout << "\n";

    std::partial_sort(widgets.begin(),
                      widgets.begin() + 5,
                      widgets.end(),
                      qualityCompare);

    for (int i = 0; i < SIZE; ++i)
        std::cout << widgets[i];
    std::cout << "\n";

    return 0;
}