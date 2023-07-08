__Specify comparison types for associative containers of pointers__

* you have a set of string* pointers and you insert the names of some animals
into the set, with expectation of the names being stored in a sorted fashion. but you don't see that at all. Instead, you get a set of four hexadecimal numbers.

* If you want the string* pointers to be stored in the set in an order determined by the string values, you can't use the default comparison functor class less<string*>. You must instead write your own comparison functor class, one whose objects take string* pointers and order them by the values of the strings they point to.

* Anytime you create associative containers of pointers, figure you're probably going to have to specify the container's comparison type, too. Most of the time, your comparison type will just dereference the pointers and compare the pointed-to objects (as is done in StringPtrLess above).

* This Item is about associative containers of pointers, but it applies equally well to containers of objects that act like pointers, e.g., smart pointers and iterators. If you have an associative container of smart pointers or of iterators, plan on specifying the comparison type for it. too.

*  Just as generic dereferencing functor is likely to be suitable as the comparison type for an associative container of T*, it's likely to work as the comparison type for containers of iterators and smart pointers to T objects, too.