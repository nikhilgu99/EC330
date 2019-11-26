# HW 2

### Problem 3
Write and briefly explain the following C++ function:
void MaxIncSeq (int *nums, int len);
that accepts an integer array, nums, containing len > 0 positive integers, and prints
out, in a single line, the maximum length increasing sequence in the input array. An
increasing sequence is defined as a sequence of numbers increasing in magnitude
(should not include duplicates). These do not need to be located in adjacent cells of
the input array, but do need to be located in increasing indices of the array.

For example, if [nums] contains [1 5 3 2 4] and len==5, the function should print the
sequence 1 3 4 (or 1 2 4).

If [nums] contains [7 4 1 10 23 2] and len==6, the function should print the sequence
1 10 23 (or 7 10 23).

Your program will be compiled with a main function on the lab computers. You may
assume that the std namespace is being used and the following standard libraries have
been included: iostream, vector. Try to make your function as efficient as you can. 
