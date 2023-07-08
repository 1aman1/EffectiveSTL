__Follow remove-like algorithms by erase if you really want to remove something__

* remove doesn't "really" remove anything, because it can't.

* remove's behavior sounds spiteful, but it's simply a fallout of the way the algorithm operates. 

* Internally, remove walks down the range, overwriting values that are to be "removed" with later values that are to be retained. The overwriting is accomplished by making assignments to the elements holding the values to be overwritten

* it's enough to understand that remove doesn't eliminate any elements from a container, because it can't. Only container member functions can eliminate container elements.

* Passing remove's return value as the first argument to the range form of erase is so common, it's idiomatic. In fact, remove and erase are so closely allied, the two are merged in the std::list member function remove. This is the only function in the STL named remove that eliminates elements from a container

* Frankly, calling this function remove is an inconsistency in the STL. The analogous function in the associative containers is called erase, and list's remove should be called erase, too. It's not, however, so we all have to get used to it.

* Once you understand that remove can't "really" remove things from a container, using it in conjunction with erase becomes second nature

* The only other thing you need to bear in mind is that remove isn't the only algorithm for which this is the case. There are two other "remove-like" algorithms: remove_if and unique.

* Just as list::remove really removes things (and does so more efficiently than the erase-remove idiom). list::unique really removes adjacent duplicates (also with greater efficiency than would erase-unique