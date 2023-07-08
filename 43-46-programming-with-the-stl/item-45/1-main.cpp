#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
    list<int> sv = {1, 2, 3, 4, 5, 5, 7};
    // list<int> usv = {6, 1, 1, 3, 2, 5};

    // auto itr = lower_bound(begin(sv), end(sv), 6);
    // auto itr = upper_bound(begin(sv), end(sv), 6);

    // if (itr != sv.end())
    //     cout << distance(sv.begin(), itr);
    // else
    //     cout << "\n";

    auto [first, second] = equal_range(begin(sv), end(sv), 2);

    if (first != second)
    {

        cout << *first << *second;
        // cout << distance(sv.begin(), first) << endl;
        // cout << distance(sv.begin(), second) << endl;
    }
    else
        cout << "\n";

    return 0;
}