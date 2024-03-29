__Choose your containers with care__

%% GIST - your requirements may silently be telling you which container specifically they need.

Different requirements when understood in depth, may describe what type of container is best suited for them.
Associative / sequence / hashed Associative / hashed sequence

* Standard STL sequence containers @ vector, string, deque, list.

* Standard STL associative containers @ map, multimap, set, multiset.

* non Standard sequence containers @ slist, rope.

* non Standard associative containers @ hash_map, hash_multimap, hash_set, hast_multiset.

* vector<char> as a replacement for string

* vector as a replacement for Standard associative containers.

* Contiguous-memory containers (also known as array-based containers) store their elements in one or more (dynamically allocated) chunks of memory, each chunk holding more than one container element. If a new element is inserted or an existing element is erased, other elements in the same memory chunk have to be shifted up or down to make room for the new element or to fill the space formerly occupied by the erased element. This kind of movement affects both performance and exception safety (as we'll soon see). The standard contiguous-memory containers are vector, string, and deque. The nonstandard rope is also a contiguous-memory container.

* Node-based containers store only a single element per chunk of (dynamically allocated) memory. Insertion or erasure of a container element affects only pointers to nodes, not the contents of the nodes themselves, so element values need not be moved when something is inserted or erased

* Do you need to be able to insert a new element at an arbitrary position in the container? If so, you need a sequence container: associative containers won't do.
* Do you care how elements are ordered in the container? If not, a hashed container becomes a viable choice. Otherwise, you'll want to avoid hashed containers.
* Must the container be part of standard C++? If so, then eliminates hashed containers, slist, and rope.

* What category of iterators do you require? If they must be random access iterators, you're technically limited to vector, deque, and string, but you'd probably want to consider rope, too. If bidirectional iterators are required, you must avoid slist as well as one common implementation of the hashed containers

* Is it important to avoid movement of existing container elements when insertions or erasures take place? If so, you'll need to stay away from contiguous-memory containers

* Does the data in the container need to be layout-compatible with C? If so, you're limited to vectors

* Is lookup speed a critical consideration? If so, you'll want to look at hashed containers, sorted vectors, and the standard associative containers — probably in that order.

* Do you mind if the underlying container uses reference counting? If so, you'll want to steer clear of string, because many string implementations are reference-counted

* Do you need transactional semantics for insertions and erasures? That is, do you require the ability to reliably roll back insertions and erasures? If so, you'll want to use a node-based container. If you need transactional semantics for multiple-element insertions , you'll want to choose list, because list is the only standard container that offers transactional semantics for multiple-element insertions. Transactional semantics are particularly important for programmers interested in writing exception-safe code. (Transactional semantics can be achieved with contiguous-memory containers, too, but there is a performance cost, and the code is not as straightforward. To learn more about this, consult Item 17 of Sutter's Exceptional C++


* Do you need to minimize iterator, pointer, and reference invalidation? If so, you'll want to use node-based containers, because insertions and erasures on such containers never invalidate iterators, pointers, or references (unless they point to an element you are erasing). In general, insertions or erasures on contiguous-memory containers may invalidate all iterators, pointers, and ref-erences into the container.

* Would it be helpful to have a sequence container with random access iterators where pointers and references to the data are not invalidated as long as nothing is erased and insertions take place only at the ends of the container? This is a very special case, but if it's your case, deque is the container of your dreams. (Interestingly, deque's iterators may be invalidated when insertions are made only at the ends of the container, deque is the only standard STL container whose iterators may be invalidated without also invalidating its pointers and references.)