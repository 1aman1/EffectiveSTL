__Avoid in-place key modification in set and multiset__

* Like all the standard associative containers, set and multiset keep their elements in sorted order, and the proper behavior of these containers is dependent on their **remaining sorted**.

* if you perform any in-place modifications of container elements, you are responsible for making sure that the container remains sorted.

* It's especially simple for map and multimap, because programs that attempt to change the value of a key in these containers won't compile.

* That's because the elements in an object of type map<K, V> or multi-map<K, V> are of type pair<**const K**, V>. Because the type of the key is const K. it ***can't be changed***.

* Well, you can probably change it if you employ a **const_cast**, You've surely heard that casts are dangerous, and I believe you should avoid them whenever you can. To perform a cast is to shuck temporarily the safety of the type system, and the pitfalls that can happen when you leave your safety net behind.

* Most casts can be avoided, and that includes the ones we've just considered. If you want to change an element in a set, multiset, map, or multimap in a way that always works and is always safe, do it in five simple steps:

* ***Locate the container element -> Make a copy of the element to be modified -> Remove the element from the container -> Modify the copy so it has the value you want -> Insert the new value into the container.***