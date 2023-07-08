#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

void print(const int x) { cout << x << " "; }

int main()
{

    set<int, less_equal<int>> s;
    s.insert(10);

    s.insert(10);

    // set carries two different copies now, based on comparison function that we provided and how it evaluated internally looks like below

    // !(10A<= 10B)&&!(10B<= 10A) => false

    for_each(begin(s), end(s), print);

    std::cout << "\n";

    return 0;
}