__make copying cheap & correct__

%% GIST Make a container of type T*, instead of container of type T

• Containers hold objects, but not the ones you give them. Furthermore, when you get an object from a container, the object you get is not the one that was in the container. Instead, when you add an object to a container (via. e.g., insert or push_back, etc.), what goes into the container is a copy of the object you specify. When you get an object from a container (via. e.g., front or back), what you get is a copy of what was contained. Copy in, copy out. That's the STL way.

> An easy way to make copying efficient, correct, and immune to the slicing problem is to create containers of pointers instead of containers of objects. That is, instead of creating a container of Widget, create a container of Widget*. Copying pointers is fast, it always does exactly what you expect (it copies the bits making up the pointer), and nothing gets sliced when a pointer is copied.

> Yes, STL containers make copies, and yes, you need to understand that, but don't lose sight of the fact that they're still a big step up from arrays.