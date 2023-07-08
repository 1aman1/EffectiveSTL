__When using containers of newed pointers, remember to delete the pointers before the container is destroyed__

• when the containers hold pointers to objects allocated with new, they're not right enough. Sure, a container of pointers will destroy each element it contains when it (the container) is destroyed, but the "destructor" for a pointer is a no-op! It certainly doesn't call delete

• Each of vwp's elements is destroyed when vwp goes out of scope, but that doesn't change the fact that delete was never used for the objects conjured up with new. Such deletion is your responsibility, not that of your vector.

• One more thing, which may make you feel bad is "This is a feature'. Only you know whether the pointers should be deleted.

• All you really need to remember is that STL containers are smart, but they're not smart enough to know whether to delete the pointers they contain. To avoid resource leaks when you have containers of pointers that should be deleted, you must either replace the pointers with smart reference-counting pointer objects (such as Boost's shared_ptr) or you must manually delete each pointer in the container before the container is destroyed.