#include <iostream>
#include <algorithm>
#include <vector>

class Widget
{
    int v;

public:
    Widget() { v = 7; }
    int getWidget() { return v; }
};

void outsideFunc()
{
    typedef std::vector<Widget> WidgetContainer;
    WidgetContainer Widgets;

    for (int i = 0; i < 10; ++i)
    {
        Widgets.push_back(Widget());
    }

    for (auto itr = Widgets.begin(); itr != Widgets.end(); ++itr)
    {
        std::cout << itr->getWidget() << " ";
    }
}

int main()
{
    outsideFunc();

    outsideFunc();

    return 0;
}