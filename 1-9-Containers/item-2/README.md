__Beware the illusion of container-independent code__

%% GIST - same code can accomodate all kinds of containers is an expensive myth. 

* The STL is based on generalization. Arrays are generalized into containers and parameterized on the types of objects they contain. Functions are generalized into algorithms and parameterized on the types of iterators they use. Pointers are generalized into iterators and parameterized on the type of objects they point to.

* That's just the beginning. Individual container types are generalized into sequence and associative containers, and similar containers are given similar functionality. Standard contiguous-memory containers offer random-access iterators, while standard node-based containers provide bidirectional iterators. Sequence containers support push_front and/or push_back, while associative containers don't. Associative containers offer logarithmic-time lower_bound, upper_bound, and equal_range member functions, but sequence containers don't. 

* many programmers try to pursue it ( the generalization ) in a different manner. Instead of committing to particular types of containers in their software, they try to generalize the notion of a container so that they can use, say, a vector, but still preserve the option of replacing it with something like a deque or a list later — all without changing the code that uses it. That is, they strive to write container-independent code. This kind of generalization, well-intentioned though it is, is almost always misguided

* Suppose, then, you aspire to write code that can be used with the most common sequence containers: vector, deque, and list. Clearly, you must program to the intersection of their capabilities, and that means no uses of reserve or capacity, because deque and list don't offer them. The presence of list also means you give up operator[], and you limit yourself to the capabilities of bidirectional iterators. That, in turn, means you must stay away from algorithms that demand random access iterators, including sort, stable_sort, partial_sort, and nth_element.

* If you violate any of those restrictions, your code will fail to compile with at least one of the containers you want to be able to use. The code that will compile is more insidious.

* The main culprit is the different rules for invalidation of iterators, pointers, and references that apply to different sequence containers.

* When all is said and done, you're left with a "generalized sequence container" where you can't call reserve, capacity, operator[], push_front, pop_front, splice, or any algorithm requiring random access iterators: a container where every call to insert and erase takes linear time and invalidates all iterators, pointers, and references: and a container incompatible with C where bools can't be stored. Is that really the kind of container you want to use in your applications? I suspect not.

* Face the truth: it's not worth it. The different containers are different, and they have strengths and weaknesses that vary in significant ways. They're not designed to be interchangeable, and there's little you can do to paper that over. If you try, you're merely tempting fate, and fate doesn't like to be tempted.

* if you have an object of type 
map< string, vector<Widget>::iterator, CIStringCompare>, and you want to walk through the map using const_iterators, do you really want to spell out

map<string, vector<Widget>::iterator, CIStringCompare>::const_iterator, more than once? 
Once you've used the STL a little while, you'll realize that typedefs are your friends.

* A typedef doesn't prevent a client from doing (or depending on) anything they couldn't already do (or depend on). You need bigger ammunition if you want to limit client exposure to the container choices you've made. You need classes.

* AMMUNITION : To limit the code that may require modification if you replace one container type with another, hide the container in a class, and limit the amount of container-specific information visible through the class interface. For example, if you need to create a customer list, don't use a list directly. Instead, create a CustomerList class, and hide a list in its private section:

* Well, maybe. Later you may discover that you don't need to insert or erase customers from the middle of the list as often as you'd anticipated, but you do need to quickly identify the top 20% of your customers

* When you consider this kind of change, you still have to check every CustomerList member function and every friend to see how they'll be affected (in terms of performance and iterator/pointer/reference invalidation, etc.), but if you've done a good job of encapsulating CustomerList's implementation details, the impact on CustomerList clients should be small. You can't write container-independent code, but they might be able to


* 