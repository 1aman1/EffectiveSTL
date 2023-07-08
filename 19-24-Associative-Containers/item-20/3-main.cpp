#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

struct DereferenceLess
{
    template <typename PtrType>
    bool operator()(PtrType pT1,       // parameters are passed by
                    PtrType pT2) const // value, because we expect them
    {
        return *pT1 < *pT2;
    }
};

struct Dereference
{
    template <class T>
    const T &operator()(const T *pString)
    {
        return *pString;
    }
};

int main()
{
    typedef set<string *, DereferenceLess> StringPtrSet;
    StringPtrSet ssp;

    ssp.insert(new string("Walker"));
    ssp.insert(new string("Cain"));
    ssp.insert(new string("Luke"));
    ssp.insert(new string("Addie"));

    transform(ssp.begin(), ssp.end(),               // "transform" each
              ostream_iterator<string>(cout, "\n"), // element in ssp by
              Dereference());

    return 0;
}