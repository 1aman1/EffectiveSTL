__vector and string__

* It says string is typedef for basic_string<char>, and wstring for basic_string<wchar_t>

* It tells, when you choose using an array with dynamically allocated memory. You adopt few responsibilities as well: first, you have to de-allocate what was allocated earlier.

* second, you have to match the de-allocation with the allcation i.e., for de-allocation of array, delete []arr has to be used otherwise proceeding can be undefined.

* and third, remember to use delete only exactly once. And not end up de-allocating something more than one time, which was allocated only once.

* It emphasizes that whenever you think of going to create arr with new. Choose vector/string instead. It offers flexible sizing, as you add or remove the elements from it.

* When a vector is destroyed, it automatically calls it's destructor to erase the elements stored and  de-allocate the memory.

* For the concerns to support legacy code, it is not much of an issue generally. go ahead and use string and vector.

* There are ways to pass vector & string to methods that expect an array.

* For some reasons like reference counting implementations(some behind the scene mechanism to avoid moving of elements/copying that can improve performance overall). And the same time, this mechanism can end up costing more than the effort it saves in a multi-threaded environment.

* If you're dynamically allocating arrays, you're probably taking on more work than you need to. To lighten your load, use vectors or strings instead.