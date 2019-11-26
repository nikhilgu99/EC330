// NAME: Nikhil Gupta	BU ID: U86132587
// COLLABORATOR: Sharith Godamanna BU ID: U13031813

#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <map> 
#include <unordered_map>

#include "Huffman.h"

using namespace std;

// Function to allocate a new tree node
Node* getNode(string data, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->data = data;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void Huffman::buildHuffmanTree(char* characters, int* freq, int size)
{
	priority_queue<Node*, vector<Node*>, comp> pq;

    char temp;
    string str;

    for(int i = 1; i < size; i++){
        if(freq[i-1] == freq[i]){
            temp = characters[i-1];
            characters[i-1] = characters[i];
            characters[i] = temp; 
        }
    }

    unordered_map<char, int> fre;
    for (int i = 0; i < size; i++) {
        fre[characters[i]] = freq[i];
        chars.push_back(characters[i]);
        //cout << chars[i] << " " << characters[i] << endl;
    }

    for (auto pair: fre) {
        string s(1,pair.first);
        pq.push(getNode(s, pair.second, nullptr, nullptr));
    }

    
    while (pq.size() != 1)
    {

        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        int sum = left->freq + right->freq;
        str = left->data + right->data;
        pq.push(getNode(str, sum, left, right));
    }

    this->root = pq.top(); // root stores pointer to root of Huffman Tree
    this->pq = pq;
    this->size = size;

}

void Huffman::printCodes(){

	cout << "Huffman Code \t Character" << endl;
	cout << "--------------------------" << endl;

	Node *temp = this->root;
	for(int x = size - 1; x >= 0; x--){
		temp = this->root;
		string s = string(1,this->chars[x]);
		string huff = "";

		while(s != temp->data){
			if(s == temp->left->data){
				huff = huff + "0";
				cout << huff << "\t \t" << s << endl;
                bits.insert({ huff, this->chars[x] }); 
				break;
			}
			else if(s == temp->right->data){
				huff = huff + "1";
				cout << huff << "\t \t" << s << endl;
                bits.insert({ huff, this->chars[x] }); 
				break;
			}
			else if(temp->left->data.find(s) != string::npos){
				temp = temp->left;
				huff = huff + "0";
			}
			else if(temp->right->data.find(s) != string::npos){
				temp = temp->right;
				huff = huff + "1";
			}
		}

	}
}

void Huffman::decodeText(string fileName){
    multimap <string, char> :: iterator itr;


    ifstream file(fileName);
    string str;
    getline(file, str);

    string temp = "";

    cout << endl;
    cout << "The decoded text is: ";
    for (int i = 0; i < str.length(); i++){
        temp = temp + str[i];
        for (itr = bits.begin(); itr != bits.end(); ++itr) 
        { 
            if(temp == itr->first){
                cout << itr->second;
                temp = "";
            }
        } 

    }
    cout << endl;

}
