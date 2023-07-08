__Avoid using vector of bool.__

* This vector<bool> according to the definition to be a STL container, doesn't really meet the conditions. It is not holding bools is the first. Second, it is not a STL container.

* section 23.1 of Standard C++ asks any container to be qualified as a  STL container to compile this code 
>> T* p = &container[0];

* Had vector<bool> been a genuine bool holding container, this wouldn't have been a problem. Instead, vector<bool> actually is a packed representation of bools designed to save space.

* Internally, it uses moral equivalent of bool - bitfields.

* but there is an important difference between true bools and bitfields masquerading as bools. You may create a pointer to a real bool, but pointers to individual bits are forbidden.

* References to individual bits are forbidden, too.

* To deal with this difficulty, vector<bool>::operator[] returns an object that acts like a reference to a bit, a so-called proxy object.

* The standard library provides two alternatives that suffice almost all the time. The first is deque<bool>.

* A deque offers almost everything a vector does (the only notable omissions are reserve and capacity), and a deque<bool> is an STL container that really contains bools.

* The second alternative to vector<bool> is bitset. bitset isn't an STL container, but it is part of the standard C++ library. Unlike STL containers, its size (number of elements) is fixed during compilation, so there is no support for inserting or erasing elements. Furthermore, because it's not an STL container, it offers no support for iterators. Like vector<bool>, however, it uses a compact representation that devotes only a single bit to each value it contains.