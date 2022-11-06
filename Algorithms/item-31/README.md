__Know your sorting options__

* sort is a wonderful algorithm, but there's no point in squandering wonder where you don't need it.

* if you have a vector of Widgets and you'd like to select the 20 highest-quality Widgets to send to your most loyal customers, you need to do only enough sorting to identify the 20 best Widgets; the remainder can remain unsorted

* Then what you need is a partial sort, and there's an algorithm called partial_sort that does exactly what the name suggests.

* If all you care about is that the 20 best Widgets go to your 20 best customers, but you don't care which Widget goes to which customer, partial_sort gives you more than you need.

* The STL has an algorithm that does exactly what you want,it's called nth_element

* partial_sort sorts the elements in positions 1-20, while nth_element doesn't.

* partial_sort is not stable. Neither is nth_element, sort, too, fails to offer stability, but there is an algorithm, stable_sort.

* to move all the Widgets with a quality rating of 2 or better to the front of widgets, we can use a fn that identifies widgets that qualify using the help of partition. If relevant ordering is important for equivalent widgets, use stable_partition.

* The algorithms sort, stable_sort, partial_sort, and nth_element require random access iterators, so they may be applied only to vectors, strings, deques, and arrays.

* The only container where we might like to use sort, stable_sort, partial_sort, or nth_element, but can't, is list, and list compensates somewhat by offering its sort member function. (Interestingly, list::sort performs a stable sort.) 

* If you want to sort a list, then, you can, but if you want to use partial_sort, or nth_element on the objects in a list, you have to do it indirectly. One indirect approach is to copy the elements into a ontainer with random access iterators, then apply the desired algorithm to that. Another is to create a container of list::iterators, use the algorithm on that container, then access the list elements via the iterators. A third is to use the information in an ordered container of iterators to iteratively splice the list's elements into the positions you'd like them to bein.

* Let's summarize your sorting options. 

* If you need to perform a full sort on a vector, string, deque, or array, you can use sort or stable_sort. 

* If you have a vector, string, deque, or array and you need to put only the top n elements in order, partial_sort is available.

* If you have a vector, string, deque, or array and you need to identify the element at position n or you need to identify the top n elements without putting them in order nth_element is at your beck and call.

* If you need to separate the elements of a standard sequence container or an array into those that do and do not satisfy some criterion, you're probably looking for partition or stable_partition.

* If your data is in a list, you can use partition and stable_partition directly, and you can use list-sort in place of sort and stable_sort. If you need the effects offered by partial_sort or nth_element, you'll have to approach the task indirectly.

* algorithms that tend to use fewer resources (time and space) listed before those that require more:
1. partition 4. partial_sort
2. stable_partition 5. sort
3. nth_element 6. stable_sort

* My advice on choosing among the sorting algorithms is to make your selection based on what you need to accomplish, not on performance considerations. If you choose an algorithm that does only what you need to do (e.g., a partition instead of a full sort) you're likely to end up with code that's not only the clearest expression of what you want to do. it's also the most efficient way to accomplish it using the STL.