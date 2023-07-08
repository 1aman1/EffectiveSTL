#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

using namespace std;

void print(const string *ps) // print to cout the
{                            // object pointed to
    cout << *ps << endl;     // by ps
}

int main()
{

    // set<string *> ssp; // ssp = "set of string ptrs"

    set<string *, less<string *>> ssp;

    ssp.insert(new string("Wombat"));
    ssp.insert(new string("Lemur"));
    ssp.insert(new string("Penguin"));
    ssp.insert(new string("Anteater"));

    // INCOMPATIBLE BECAUSE OF PTR TO STRING, INSTEAD OF STRING
    
    // copy(ssp.begin(), ssp.end(),
    //      ostream_iterator<string>(cout, "\n"));

    // PRINTS HEXADECIMAL ADDRESSES

    // for (set<string *>::const_iterator i = ssp.begin(); // you expect to see
    //      i != ssp.end();                                // this: "Anteater"
    //      ++i)                                           //"Lemur”,"'Penguin”,
    //     cout << *i << endl;

    for_each(ssp.begin(), ssp.end(), print);

    return 0;
}