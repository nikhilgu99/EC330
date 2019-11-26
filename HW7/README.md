# HW 7

### Problem 4

You are provided with a map representing characters and their frequencies, in  
main.cpp, as well as a text file, encoded.txt, containing Huffman encoded text.  
Implement a Huffman class that generates a Huffman tree from the provided map,  
prints the generated tree in table format (containing Character and Huffman code  
columns), and then prints out the decoded (i.e. uncompressed) text version of the  
provided file.

The Huffman class must include a min heap priority queue member, which will be  
utilized to generate the Huffman tree, as well as the following methods:  

• buildHuffmanTree – accepts an array of characters, an array of integer  
frequencies, and the integer size of these arrays, and constructs a Huffman Tree  
from the input.  
• printCodes – prints the Huffman tree in a table format.  
• decodeText – accepts a pointer to a file name containing a Huffman code encoded  
text, and prints out the plain text version of the file.  

Your code should be able to compile and run with a main.cpp file similar to the one  
provided, to generate the following output:  

Huffman Code Character  
--------------------------  
0   g  
10  o  
110 e  
111 l  
The decoded text is: googgle  
To compile these three files on the lab computers, use the provided makefile, and type  
the following two commands:  
> module load gcc  
> make  
