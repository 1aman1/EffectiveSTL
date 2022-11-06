__use reserve to avoid expensive re-allcations__

* One of the most marvelous things about STL containers is that they automatically grow to accommodate as much data as you put into them, provided only that you don't exceed their maximum size.

* whenever we exceed the memory allocated for the container, system does the re-allocation in these steps: 
> Allocate new memory few multiples of the existing capacity.
> copy all the elements from old memory to new location.
> Destroy objects in old memory.
> Release the old memory.

* These steps can be expensive, they invalidate all the iterators/pointers/references that point into the vector/string.

* all iterators/pointers/references from the insertion point to the end of the vector/string get invalidated upon insertion.

* Hence operations that by nature perform an insertion, should be checked first with size+capacity relationship, and this way you can predict which insert will cause the re-allocation.

* there are two common ways to use reserve to avoid unneeded reallocations. 
> first, is applicable when you know exactly or approximately how many elements will ultimately end up in your container. In that case, you simply reserve the appropriate amount of space in advance. 
> The second way is to reserve the maximum space you could ever need. then, once you've added all your data, trim off any excess capacity