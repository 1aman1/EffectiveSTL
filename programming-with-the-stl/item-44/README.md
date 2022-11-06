__Prefer member functions to algorithms with the same names__

* Most of the time, you'll want to use the member functions instead of the algorithms. There are two reasons for this. 

* First, the member functions are faster. 

* Second, they integrate better with the containers (especially the associative containers) than do the algorithms.

* That's because algorithms and member functions that share the same name typically do not do exactly the same thing

* For the standard associative containers, then, choosing member functions over algorithms with the same names offers several benefits.

* First, you get logarithmic-time instead of linear-time performance. 

* Second, you determine whether two values are "the same" using equivalence, which is the natural definition for associative containers. 

* Third, when working with maps and multimaps, you automatically deal only with key values instead of with (key. value)

* A significant difference between the sort algorithm and list's sort function is that the former can't be applied to lists. Being only bidirectional iterators, list's iterators can't be passed to sort.

* A gulf also exists between the behavior of the merge algorithm and list's merge. The algorithm isn't permitted to modify its source ranges, but list-merge always modifies the lists it works on.

* you should prefer the member function over algorithm eponym bcoz It's almost certain to be more efficient, and it's likely to be better integrated with the container's usual behavior, too