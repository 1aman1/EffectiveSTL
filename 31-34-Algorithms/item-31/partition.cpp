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

bool hasAcceptableQuality(const Widget &obj)
{
    return obj.data < 3;
}

int main()
{
    vector<Widget> widgets;

    for (int i = 0; i < 10; ++i)
    {
        widgets.push_back({10 - i});
        std::cout << widgets[i];
    }
    std::cout << "\n";

    vector<Widget>::iterator goodEnd = // move all widgets satisfying
        partition(widgets.begin(),     // hasAcceptableQuality to
                  widgets.end(),       // the front of widgets, and
                  hasAcceptableQuality);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << widgets[i];
    }
    std::cout << "\n";

    return 0;
}