# HW 8

### Problem 5

You are planning a delivery route through a number of cities for a big company. Your  
origin is near the Existential Typography Clinic of Wisconsin (code ETCW), meaning  
that you are to design a tour that starts and ends with this location and goes through  
all the cities on the route at least once. Your goal is to minimize the overall cost of the  
tour (i.e., the sum of the weights of all edges in the cycle). Note that you are required   
to visit all vertices, but are allowed to go through individual vertices more than once.  
Also note that your cycle does not need to be the shortest possible cycle, just best  
effort (i.e. shorter is better).  

The input file map.txt lists the cost (in dollars) of traveling between roughly 1500  
destination cities (marked by four-letter abbreviations). This cost is based primarily  
on mileage between cities, but includes the price of fuel and the like. For example,  
one entry in the file reads ETCW à RJWT: 807, indicating that travel from ETCW to  
the RJWT costs $807. You may assume that the provided input file, named map.txt is  
the only input (i.e. you may access it explicitly in your code and not expect any inputs  
to your program), and that the provided graph is undirected.  

Your solution should consist of a text file, with the weight of your cycle on the first  
line, followed by one vertex name per line denoting the vertices of your cycle. This  
solution should be provided by your program, if it is compiled and ran using your  
makefile on the lab computers. You do not have to find the very shortest cycle in the  
graph (which may be very computationally intensive) to get full credit, but you do  
have to find a “reasonably short” cycle.  

Submit a single Problem5.zip file, containing your C++ code, along with a modified  
makefile that can be used to compile and run your code on the lab computers, and a  
text file, path.txt that includes your solution (output), and explains your approach.  
