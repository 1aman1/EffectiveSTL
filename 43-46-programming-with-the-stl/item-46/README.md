__Consider function objects instead of functions as algorithm parameters.__

* passing STL function objects — objects masquerading as functions — to algorithms typically yields code that is more efficient than passing real functions

* Function objects as parameters to algorithms thus offer more than greater efficiency. They're also more robust when it comes to getting your code to compile. Real functions are useful, of course, but when it comes to effective STL programming, function objects are frequently more useful

* unlike functions, functors can have state.

* functors can be utilised with STL, for_each.

* simplicity & efficiency because sometime they can be inlined by compiler. 
