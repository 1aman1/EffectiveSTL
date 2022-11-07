__Be wary of remove-like algorithms on containers of pointers.__

* Be wary of remove-like algorithms on containers of pointers. Failure to heed this advice is just asking for resource leaks.

* If you're willing to replace the container of pointers with a container of smart pointers that perform reference counting, the remove-related difficulties wash away, and you can use the erase-remove idiom directly

* Regardless of how you choose to deal with containers of dynamically allocated pointers, be it by reference counting smart pointers, manual deletion and nullification of pointers prior to invoking a remove-like algorithm, or some technique of your own invention, the guidance of this Item remains the same: Be wary of remove-like algorithms on containers of pointers.