__Note which algorithms expect sorted ranges__

* The search algorithms binary_search, lower_bound, upper_bound, and equal_range require sorted ranges, because they look for values using binary search. Like the C library's bsearch, these algorithms promise logarithmic-time lookups, but in exchange, you must give them values that have already been put into order.

* it's not quite true that these algorithms promise logarithmic-time lookup. They guarantee such performance only when they are passed random access iterators. If they're given less powerful iterators (such as bidirectional iterators), they still perform only a logarithmic number of comparisons, but they run in linear time. That's because, lacking the ability to perform "iterator arithmetic." they need linear time to move from place to place in the range being searched.

* The quartet of algorithms set_union, set_intersection, set_difference, and set_symmetric_difference offer linear-time performance of the set-theoretical operations their names suggest. Why do they demand sorted ranges? Because without them, they couldn't do their work in linear time.

* merge and inplace_merge perform what is in effect a single pass of the mergesort algorithm: they read two sorted ranges and produce a new sorted range containing all the elements from both source ranges. They run in linear time, something they couldn't do if they didn't know that the source ranges were already sorted.

* The final algorithm that requires sorted source ranges is includes. It's used to determine whether all the objects in one range are also in another range. Because includes may assume that both its ranges are-sorted, it promises linear-time performance. Without that guarantee, it would generally run slower.

* unique and unique_copy offer well-defined behavior even on unsorted ranges. It Eliminates all but the first element from every consecutive group of equal element. If you want unique to eliminate all duplicates from a range, you must first make sure that all duplicate values are next to one another. And guess what? That's one of the things sorting does.

* In practice, unique is usually employed to eliminate all duplicate values from a range, so you'll almost always want to make sure that the range you pass unique is sorted.

* If you pass a sorted range to an algorithm that also takes a comparison function, be sure that the comparison function you pass behaves the same as the one you used to sort the range.

