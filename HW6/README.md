# HW 6

### Problem 4

This problem involves finding information in a very large data file, BigData.txt,  
similar to what you might find from the dump of a hard drive. The file can be  
obtained from the /ad/eng/courses/ec/ec330/BigData.txt. Please let us know if you  
have trouble accessing the file.  

Within this file, determine:

a. The number of unique BU-IDs in the file. A BU ID is defined as anything starting  
with a U and followed by exactly eight digits and then a non-digit.  

b. The number of “words” that contain only letters. Here, we define a word as a  
sequence of characters delimited on both sides by a white space (that is, any  
number of spaces, new lines, tabs, etc).  

c. The shortest pangram you can find within the text. A pangram is a sentence using  
every letter of the alphabet at least once, in lower case or upper case. The  
sentence may contain any non-letter characters (including white space, new line,  
etc.), and those should be counted when determining the length of the sentence. A  
sentence is defined as any substring of the file and is not necessarily delimited by  
a particular character. That is, the entire file’s content could be considered one  
long sentence.

For example, a file containing the following:

“The qUICk12brown fox3456789jumps  
over the lazy dog  
the quick bro123wn fox jumps”  

would include these valid pangrams:  

“The qUICk12brown fox3456789jumps over the lazy dog the  
quick bro123wn fox jumps”  

“The qUICk12brown fox3456789jumps over the lazy dog”  
“ver the lazy dog the quick bro123wn fox jumps”  

Provide your solutions (i.e. your output to each of the sections, along with  
a brief explanation of each of your solutions), in a file named  
Problem4.txt. Attach this file, along with your solution code as an  
attachment problem4.zip. Your code must be submitted in a single file  
named Problem4.cpp. Your code should include three functions, fourA,  
fourB, and fourC, that when run with no arguments in the same directory  
as BigData.txt produce the results that you report. In order to receive full  
credit, your solution needs to be efficient.
