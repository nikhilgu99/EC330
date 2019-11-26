/*
	Name: Nikhil Gupta
	Collaborator: Sharith Godamanna
	BU-ID: U86132587
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <algorithm>

using namespace std;

void fourA()
{
	char c;
	int i = 0;
	//int count = 0;
	bool done = false;
	string word;
    vector<string> BUIDs;
    string digit = "";

	ifstream input;
	input.open("BigData.txt");
	
	while (!input.eof()){

		input.get(c); 
		
		if (c == 'U'){
			
			digit = "U";
			while (i < 8 && !done){ 
				
				input.get(c);
				
				if(isdigit(c)){ 
					i++;
					digit += c;
				}
				else if (c == 'U'){ 
					i = 0;
					digit += "U";
				}
				else 
					done = true;
			}
			if (i == 8){
				input.get(c);
				{
					if (!isdigit(c)){
						//count++;
						BUIDs.push_back(digit);
					}
				}
			}
			i = 0; 
			done = false;
		}
	}
	//cout << count << endl;

	sort( BUIDs.begin(), BUIDs.end() );
    BUIDs.erase( unique( BUIDs.begin(), BUIDs.end() ), BUIDs.end() );
    cout << BUIDs.size() << endl;

	input.close();
}

void fourB(){
	ifstream input;
	string filename, word;
	int count = 0;

	filename = "BigData.txt";
	input.open(filename.c_str());

	while(input >> word){
		int x = 0;
		bool valid = true;

		while(x < word.length() && valid){

			if(isdigit(word.at(x))){
				valid = false;
			}

			x++;
		}

		if(valid){
			//cout << word << endl;
			count++;
		}

	}

	cout << count << endl;
}

// Returns true if the string is pangram else false 
bool checkPangram (string &str) 
{ 
    // Create a hash table to mark the characters 
    // present in the string 
    vector<bool> mark(26, false); 
  
    // For indexing in mark[] 
    int index; 
  
    // Traverse all characters 
    for (int i=0; i<str.length(); i++) 
    { 
        // If uppercase character, subtract 'A' 
        // to find index. 
        if ('A' <= str[i] && str[i] <= 'Z' && !isdigit(str[i])) 
            index = str[i] - 'A'; 
  
        // If lowercase character, subtract 'a' 
        // to find index. 
        else if('a' <= str[i] && str[i] <= 'z'  && !isdigit(str[i])) 
            index = str[i] - 'a'; 
  
        // Mark current character
	if(index >= 26){ 
		//cout << str[i] << endl;	
		//cout << "Index: " << index << endl;
	}else{
        	mark[index] = true;
	} 
    } 
  
    // Return false if any character is unmarked 
    for (int i=0; i<=25; i++) 
        if (mark[i] == false) 
            return (false); 
  
    // If all characters were present 
    return (true); 
}

void fourC(){
	char c, tempC;
    fstream input;
    
    string filename = "BigData.txt";
    
    // opening file
    input.open(filename.c_str());

    string minPan(999,'*');
	string temp = "";

    // extracting words from the file
    while (!input.eof()){
		input.get(c);
		temp = temp + c;
		while(!input.eof()){
			input.get(tempC);
			temp = temp + tempC;
			if(checkPangram(temp)){
				if(temp.size() < minPan.size()){
					//cout << temp << endl;
					minPan = temp;
				}
				
				temp = "";
				tempC = c;
				break;
			}
		}
    }

    cout << minPan << endl;	
}
