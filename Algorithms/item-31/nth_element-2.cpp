#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
    // return lhs.data > rhs.data;
}

int main()
{
    vector<Widget> widgets;
    vector<Widget>::iterator begin(widgets.begin());
    vector<Widget>::iterator end(widgets.end());
    vector<Widget>::iterator goalPosition;

    for (int i = 0; i < 10; ++i)
    {
        widgets.push_back({i});
        std::cout << widgets[i];
    }
    std::cout << "\n";

    goalPosition = begin + widgets.size() / 2;

    nth_element(begin, goalPosition, end, // find the median quality
                qualityCompare);

    // std::cout << "\n"
            //   << (*goalPosition).data;

    return 0;
}