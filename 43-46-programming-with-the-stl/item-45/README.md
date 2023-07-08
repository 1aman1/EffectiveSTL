__Distinguish among count, find, binary search,lower_bound, upper_bound, and equal_range__

* For sorted ranges, you have other choices, and you'll definitely want to use them, count and find run in linear time, but the search algorithms for sorted ranges (binary_search, lower_bound, upper_bound, and equal_range) run in logarithmic time

* If you have a sorted range and your question is, "Is it there, and if so, where is it?" you want equal_range instead of binary_search

* To test for the existence of a value in a multiset or multimap, find is generally superior to count, because find can stop once it's found a single object with the desired value, while count, in the worst case, must examine every object in the container