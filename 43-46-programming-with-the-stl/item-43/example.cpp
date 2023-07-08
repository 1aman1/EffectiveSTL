#include <iostream>
#include <list>
#include <algorithm>
#include <queue>

class Widget
{
public:
    void redraw() const
    {
        std::cout << "redrawing\n";
    }
};

int main()
{
    std::list<Widget> container;

    Widget obj_1;
    Widget obj_2;
    container.push_back(obj_1);
    container.push_back(obj_2);

    // 1 way
    for (std::list<Widget>::iterator i = container.begin(); i != container.end(); ++i)
    {
        i->redraw();
    }

    // other way
    std::for_each(container.begin(), container.end(), std::mem_fun_ref(&Widget::redraw));

    return 0;
}