#include <iostream>
#include <algorithm>
#include <vector>

class Widget
{
public:
    int v;
    Widget() { v = 11; }
};

int main()
{
    Widget bestWidget;

    // 1 way
    std::vector<Widget> vw;

    std::vector<Widget>::iterator itr_1 = std::find(vw.begin(), vw.end(), bestWidget);

    // other way, better way
    typedef std::vector<Widget> WidgetContainer;
    typedef std::vector<Widget>::iterator WCIterator;

    WidgetContainer vw;

    WCIterator itr_2 = std::find(vw.begin(), vw.end(), bestWidget);

    return 0;
}