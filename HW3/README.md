# HW 3

### Problem 3

You are provided with a partial implementation of a templated linked list in files
LinkedList.h and main.cpp. The list nodes are also templated, and contain a data field,
which doubles as key, and pointers to all directions (i.e. to the next node, previous
node, node above, and node below). For this assignment, you will only be utilizing
the next and previous nodes. Your code will be tested with numerical data values and
characters.

Note: While the declaration and implementation of classes are typically split between
.cpp and .h files, some compilers cannot handle templates in separate files, therefore
the declaration and implementation are provided in a single .h file.
Implement an ordered doubly linked list (with keys in increasing order). The linked
list class should contain the following methods:

• LinkedList – Constructor of a linked list containing two elements: a minimum
value and a maximum value (corresponding to -∞ and +∞) of the given type,
both should be passed to the function.

• ~LinkedList – Destructor of a linked list.

• search – Accepts a location in the linked list to start searching from (forward
only). Tests if a value x is contained in the linked list, returns its location (pointer
to its associated node) if it exists, or the location where new node should be
inserted (pointer to the previous node), if it does not exist.

• insert – Inserts node with data directly after the node in the specified location (that
is assumed to be the correct position that corresponds to its key), returns pointer
to new node. Note that search will generally be called first, return the specified
location for inserting the new node, and then insert will be called. You may
assume that no duplicates are allowed.

• printData – Prints the content of the linked list (data values only).

• print – Print the entire content of the linked list (including nodes’ addresses and
pointers) for debugging purposes.
