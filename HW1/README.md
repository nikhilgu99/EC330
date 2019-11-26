# HW 1

### Problem 4
The function receives as input two file names, of files containing words, one per line,
in alphabetical order (you may assume only lower-case letters). The function creates
an output file, output.txt, which contains the merged content of the two input files,
one word per line, in alphabetical order.

Your main function should receive two file names from the command line, call the
MergeFiles function, and exit.

### Problem 5
The function makes a copy of a string, src, transposing (flipping) every pair of  
characters, and writes it into dest. If the string has odd length, then the last character  
is not transposed with the ’\0’ character (the output string is always the same length  
as the input string). For example, given an input (src) of "abcde" the string produced   
(written into dest) would be "badce". As another example, if the input were 1234,  
then the function would produce the string 2143. You may assume that dest points to  
a writeable area with space for each character in src when your function is first called.  
Your main function should receive a string from the command line, call the strXpos  
function with the provided string, and print out the output returned by the function.  
