__Use "the swap trick" to trim excess capacity__

* to trim the excess capacity for a vector / strinng, we use command < std::vector<contestants>(contestants).swap(contestants) > which creates a temmporary vector, and allocates only the memory needed currently by the vector. And in the end of the statement, removing the bloated vector with unused memory.