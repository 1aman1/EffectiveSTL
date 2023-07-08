__Use distance and advance to convert a container's const_iterators to iterators__

* To get an iterator pointing to the same container element as a const_iterator, create a new iterator at the beginning of the container, then move it forward until it's as far from the beginning of the container as the const_iterator is!

* This task is facilitated by the function templates advance and distance, both of which are declared in <iterator>, distance reports how far apart two iterators into the same container are, and advance moves an iterator a specified distance.

* But this doesn't really go the same way, the declaration of template distance is the cause behind it.

* The call to distance with two params, one iterator and the other const iterator fails, and it can be obviated by a simple modification and advising compiler to not deduce the type for distance(declaration).

* advance(i, distance<ConstIter>(i, ci)); // provide  explicit type

* How efficient is this technique? The answer is simple. It's as efficient as the iterators allow it to be. For random access iterators (such as those sported by vector, string, and deque), it's a constant-time operation. For bidirectional iterators (i.e., those for all other standard containers and for some implementations of the hashed
containers (see Item 25)), it's a linear-time operation.