__Understand the difference between equality and equivalence__

* when you ask find to locate the first object in a range with a particular value, find has to be able to compare two objects to see if the value of one is the same as the value of the other. Similarly, when you attempt to insert a new element into a set; set::insert has to be able to determine whether that element's value is already in the set.

* because "persephone" is equivalent to "Persephone", but it's not equal to it (because string("'persephone") !=string("Persephone")).

* THis gives one strong reason why you should prefer member functions (like set::find) to their non-member counterparts.

* The long and short of it is that by using only a single comparison function and by employing equivalence as the arbiter of what it means for two values to be "the same." the standard associative containers sidestep a whole host of difficulties that would arise if two comparison functions were allowed. Their behavior may seem a little odd at first (especially when one realizes that member and non-member find may return different results), but in the long run, it avoids the kind of confusion that would arise from mixing uses of equality and equivalence within standard associative containers.

