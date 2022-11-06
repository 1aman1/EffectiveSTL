__Never create containers of auto_ptrs__ 

* This is a nasty trap to fall into, and that's why the Standardization Committee worked so hard to make sure you're not supposed to be able to fall into it. Honor its work on your behalf, then, by never creating containers of auto_ptrs, even if your STL platforms allow it.

* If your goal is a container of smart pointers, this doesn't mean you're out of luck. Containers of smart pointers are fine. It's just that auto_ptr is not such a smart pointer. Not at all.