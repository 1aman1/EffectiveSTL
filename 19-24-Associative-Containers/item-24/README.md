__Choosing carefully between map::operator[] and map-insert__

* Efficiency considerations lead us to conclude that insert is preferable to operator[] when adding an element to a map, and both efficiency and aesthetics dictate that operator[] is preferable when updating the value of an element that's already in the map.

* If you're updating an existing map element, operator[] is preferable, but if you're adding a new element, insert has the edge.