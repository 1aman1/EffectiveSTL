__Prefer range member functions to their single-element counterparts__

* Assign member function, a convenient beast that too many programmers overlook. It's available for all the standard sequence containers (vector, string, deque, and list). Range member functions tend to lead to code that is clearer and more straightforward.

* Too many STL programmers overuse copy, so the advice I just gave bears repeating: Almost all uses of copy where the destination range is specified using an insert iterator should be replaced with calls to range member functions.

* It's generally less work to write the code using the range member functions.

* Range member functions tend to lead to code that is clearer and more
straightforward.

*  they exhibit higher performance.

* That's a troika that's hard to beat.
