This task builds on the Linked List problem from the previous homework. Your
starting point should be your implemented LinkedList.h, which you should
incorporate into this new design.

You are provided with a partial implementation of a templated linked list in files
SkipList.h and main.cpp. Design a skip list class, which consists of a doubly linked
with sentinel -∞, +∞ nodes at its top-most level, and contains all elements at its
bottom-most level list. A node added to any given level has a probability of ½ to be
added to the next level up, and node that is not added to a given level cannot be added
to any of the higher levels. (Thus the number of levels should be about lg(n), where n
is the number of elements.)

The skip list should contain the following methods and members:  
• SkipList – Constructor of an empty skip list consisting of the top-level list only,  
it accepts the linked lists sentinel values  
• ~SkipList() – Destructor of a skip list  
• search – Tests if a value x is contained in the skip list, returns its location in the  
bottom-most list if it exists, or the location of its predecessor in the bottom-most  
list, if does not exist  
• insert – Inserts node with data, returns true if node is inserted, false if node  
already exists and thus was not inserted  
• printData – Prints the content of the skip list (data values only)  
• print – Print the entire content of the skip list (including nodes’ addresses and  
pointers)  
• topList – pointer to the top-most list of the skip list  
Note that the sentinel values are dependent on the type T, and therefore may be  
declared as variables.  
The printData function in the provided main.cpp could give the following output: -2147483648 2147483647  
-2147483648 3 7 2147483647  
-2147483648 3 5 7 2147483647  
-2147483648 1 2 3 5 6 7 9 2147483647  
Implement the SkipList class such that it could be compiled and ran with the provided  
main.cpp file. To do so, you are allowed to add methods and members to the  
LinkedList class and to the SkipList class.  
