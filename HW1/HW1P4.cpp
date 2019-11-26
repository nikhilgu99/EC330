/*

	Name: Nikhil Gupta
	BU e-mail: nikhilgu@bu.edu

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void MergeFiles(string file1, string file2);

int main(int argc, char *argv[]){

	MergeFiles(argv[1], argv[2]);

	return 0;
}

void MergeFiles(string file1, string file2){
	vector<string> words;

	ifstream in1;	//Get words from first file
	in1.open(file1.c_str());
	string word;

	while(in1 >> word){
		words.push_back(word);
	}
	in1.close();

	ifstream in2;	//Get words from second file
	in2.open(file2.c_str());

	while(in2 >> word){
		words.push_back(word);
	}
	in2.close();

	for(int j = 0; j < words.size() - 1; j++){	//Bubble sort the words
		for(int i = 0; i < words.size() - 1; i++){
			if(words.at(i).compare(words.at(i + 1)) > 0){
				string temp = words.at(i);
				words.at(i) = words.at(i + 1);
				words.at(i + 1) = temp;
			}
		}
	}

	ofstream output;	//Output the words to a text file
	output.open("output.txt");

	for(int y = 0; y < words.size(); y++){
		output << words.at(y) << endl;
	}

	output.close();
}