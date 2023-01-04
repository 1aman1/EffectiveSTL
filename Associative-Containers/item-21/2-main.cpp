#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void print(const int x) { cout << x << " "; }

struct StringPtrGreater
{
    template <typename T>
    bool operator()(const T left, const T right) const
    {
        return left < right;
    }
};

class Employee
{
    int var = 1;

public:
    const string &named const()
    {
        return var;
    }                                   // get employee name
    void setName(const string name);    // set employee name
    const string &titled const;         // get employee title
    void setTitlelconst(string &title); // set employee title
    int idNumber() const;               // get employee ID number
};

int main()
{

    set<int, StringPtrGreater> s;
    s.insert(10);

    s.insert(10);

    // set carries ONLY one copy now

    for_each(begin(s), end(s), print);

    std::cout << "\n";

    return 0;
}