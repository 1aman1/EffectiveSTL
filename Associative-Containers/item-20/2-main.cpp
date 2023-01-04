#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

// struct StringPtrLess
struct StringPtrLess : public binary_function<const string *,
                                              const string *,
                                              bool>
{
    bool operator()(const string *ps1, const string *ps2) const
    {
        return *ps1 < *ps2;
    }
};

void print(const string *ps) // print to cout the
{                            // object pointed to
    cout << *ps << endl;     // by ps
}

int main()
{
    typedef set<string *, StringPtrLess> StringPtrSet;
    StringPtrSet ssp;

    ssp.insert(new string("Walker"));
    ssp.insert(new string("Cain"));
    ssp.insert(new string("Luke"));
    ssp.insert(new string("Addie"));

    for_each(ssp.begin(), ssp.end(), print);

    return 0;
}