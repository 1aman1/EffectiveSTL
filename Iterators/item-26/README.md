__Prefer iterator to const iterator, reverse_iterator, and const_reverse_iterator__

* When const_iterator is used, it is tricky and very un-efficient to get an iterator from it.

* It is not-unwise to use iterators in a general manner, unless a specific requirement asks so.

* From the perspective of const correctness (a worthy perspective), staying away from const_iterators simply to avoid potential implementation shortcomings (all of which have workarounds) seems unjustified.

* It's hard to avoid the practical conclusion that const_iterators are not only less useful than iterators, sometimes they're just not worth the trouble.