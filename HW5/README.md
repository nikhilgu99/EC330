# HW 5

### Problem 4

[Hopscotch, 50 points] Remove the key field from the table!  
Implement a Hopscotch hash table. Your implementation should utilize the provided  
HopScotchHash.h file as is, without any edits.  
Each Hopscotch table entry consists of an item represented as a string, a key that is  
used to determine the hash value, a hop bitmap field, and a Boolean value  
determining if the entry contains a value, or if it is empty.  
The MAX_DIST constant defines the maximum number of probes in a prove  
sequence, and the hash function for the table is defined as a basic division hash (i.e.  
(key) mod (table size)).  
The HopScotchHash class contains the following members:  

• table – A vector of hash entries, as described above  
• myHash – Accepts a hash key, and returns its hash value, using division hash:  
(key) mod (table size))  
• HopScotchHash – Constructor of an empty hopscotch hash table of a given size  
• Insert – Inserts a given hash entry x to the hash table  
• shiftDown – accepts a hash entry x, the desired location for x in the hash table  
(e.g. the hash value of x), and the closest open location available, makes room  
for a new hash entry x by moving other elements  
• printContent – prints the content of the hash table, as described below:    

Your program should read an input file, input.txt, consisting of one input per line,  
each input represented as a pair: a string (item name) and an integer (key), separated  
by a space. The inputs should be inserted to the table one after the other in order, and  
the final content of the hash table should be printed out in the provided format below.  
Note that you are not allowed to access the key of the hash entries directly. All hash  
values of table elements should be computed from the corresponding Hop fields.  

Sample input.txt file content (provided):  
A 7  
B 9  
C 6  
D 7  
E 8  
F 12  
G 11  
H 9  
I 6  

Expected output for the above input, with MAX_DISTANCE of 4, and table size 17:  

Index Item Hop  
0 - 0000  
1 - 0000  
2 - 0000  
3 - 0000  
4 - 0000  
5 - 0000  
6 C 1001  
7 A 1100  
8 D 0010  
9 I 0011  
10 E 0000  
11 H 0001  
12 B 0100  
13 F 0000  
14 G 0000  
15 - 0000  
16 - 0000  
