__Always have comparison functions return false for equal values__

* Create a set where ***less_equal*** is the comparison type, then insert 10 into the set.

* Now insert the same element again, and for this call to insert, the set has to figure out whether 10 is already present. We know that it is, but the set is dumb as toast, the set runs through its internal data structures looking for the place to insert 10B. 

* It ultimately has to check 10B to see if it's the same as 10A. The definition of "the same" for **associative containers is equivalence**, so the set tests to see whether 10B is equivalent to 10A. When performing this test, it naturally uses the set's comparison function that's operator <= here

* **!(10A<= 10B)&&!(10B<= 10A) => !(true)&&!(true) => false & false**

* All you need to remember is that the return value of a comparison function indicates whether one value precedes another in the sort order defined by that function. ***Equal values never precede one another, so comparison functions should always return false for equal values***.

* But what about multiset and multimap? Those containers may contain duplicates, so it will store them both, which is what the multi containers are supposed to do. right?"

* **WRONG!** You see? Unless your comparison functions always return false for equal values, you break all standard associative containers, regardless of whether they are allowed to store duplicates.

* To test this for multimap/multiset if we do an equal_range on it.  It doesn't identify a range of equal values, it identifies a range of equivalent values **REMEMBER!**

* Technically speaking, comparison functions used to sort associative containers must define a ***strict weak ordering***