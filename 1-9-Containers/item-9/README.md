__Choose carefully among erasing options.__

* the erase-remove idiom is the best way to get rid of elements with a specific value when c is a vector,string, or deque.

* This approach works for lists, too, but, the list member function remove is more efficient.

* When c is a standard associative container (i.e., a set, multiset, map, or multimap), the use of anything named remove is completely wrong.

* for associative containers, the proper way to approach the problem is to call erase. Not only does this do the right thing, it does it efficiently, taking only logarithmic time.(The remove-based techniques for sequence containers require linear time.) 

* Furthermore, the associative container erase member function has the advantage of being based on equivalence instead of equality.

* Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references. An iterator is invalidated only when the corresponding element is deleted

* As you can see, there's more to erasing container elements effectively than just calling erase. The best way to approach the matter depends on how you identify which objects to erase, the type of container they're stored in, and what (if anything) you want to do while you're erasing them.

* To eliminate all objects in a container that have a particular value, 
-> for Seq containers- use erase-remove idiom
-> for list - use remove
-> for associative containers - use erase, its efficient and does the job correctly.

* To eleminate all objects based on a predicate returning true/false
-> for seq containers - use erase - remove_if
-> for list - remove_if
-> for associative containers - either use remove_copy_if, OR walk down the container elements and post increment the iterator when passed to erase.

* To eleminate all object and perform some activity too, like logging.
-> for seq container - walk down the container and update iterator mindfully with erase's return value
-> for associative container - walk down the container and  post increment the iterator when passed to erase.