__Consider replacing associative containers with sorted vectors__

* When we are faced with the need for a data structure offering fast lookups, we immediately think of the standard associative containers, set, multiset, map, and multimap. 

* If lookup speed is really important, it's almost certainly worthwhile to consider the nonstandard hashed containers as well

* Even if guaranteed logarithmic-time lookup is what you want, the standard associative containers still may not be your best bet. Counterintuitively, it's not uncommon for the standard associative containers to offer performance that is inferior to that of the lowly vector.

* The standard associative containers are typically implemented as **balanced binary search trees.**

* For applications that use their data structures in this way, a vector is likely to offer better performance (in both time and space) than an associative container

* But not just any vector will do. It has to be a **sorted vector**, because only sorted containers work correctly with the lookup algorithms binary_search, lower_bound, equaL_range; etc.

* But why should a binary search through a (sorted) vector offer better performance than a binary search through a binary search tree, Because some things are trite but true, and one of them is that **size matters**. Others are less trite but no less true, and one of those is that **locality of reference matters**, too

* the space overhead for storing a Widget in an associative container would be at least three pointers, there is no overhead when we store a Widget in a vector: we simply store a Widget.

*  The vector itself has overhead, of course, and there may be empty (reserved) space at the end of the vector, but the per-vector overhead is typically insignificant Even if the extra space is not eliminated, it can be unimportant because that memory won't be referenced when doing a lookup.

* Assuming our data structures are big enough, they'll be split across multiple memory pages, but the vector will require fewer pages than the associative container. If you're working in an environment where virtual memory is available, it's easy to see how that can translate into a lot more page faults, therefore a system that is significantly slower for large sets of data

* I'm actually being optimistic about the associative containers here, because I'm assuming that the nodes in the binary trees are clustered together on a relatively small set of memory pages.If your STL implementation fails to take steps to improve locality of reference among tree nodes,**the nodes could end up scattered all over your address space. That would lead to even more page faults**. 

* Associative containers tend to have more problems with page faults, because, unlike contiguous-memory containers such as vector, node-based containers find it more difficult to guarantee that container elements that are close to one another in a container's traversal order are also close to one another in physical memory. **this is precisely the kind of memory organization that minimizes page faults when performing a binary search.**

* Bottom line: storing data in a sorted vector is likely to consume less memory than storing the same data in a standard associative container, and searching a sorted vector via binary search is likely to be faster than searching a standard associative container when page faults are taken into account.

* Of course, the big drawback of a sorted vector is that it **must remain sorted**! When a new element is inserted, everything beyond the new element must be moved up by one. That's **as expensive as it sounds**, and it gets even more expensive if the vector has to reallocate its underlying memory, because then all the elements in the vector typically have to be copied. 

* Similarly, Insertions and erasures are expensive for vectors, but they're cheap for associative containers. That's why it makes sense to consider using a sorted vector instead of an associative container only when you know that your data structure is used in such a way that ***lookups are almost never mixed with insertions and erasures***

* When tweaking a vector to hold third party data, we may need to provide sorting & lookup function based on value/pair.