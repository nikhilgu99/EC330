/*
/	Name: Nikhil Gupta
/	Collaborator: Sharith Godamanna
/	My BU-ID: U86132587
*/

#include <iostream>
#include <bitset>
#include "HopScotchHash.h"

using namespace std;

HopScotchHash::HopScotchHash(int size){
	vector<HashEntry> t(size);
	this->table = t;
	for(int x = 0; x < size; x++){
		table[x].item = "-";
		table[x].hop = 0;
		table[x].isActive = false;
	}
}

int HopScotchHash::myHash(const int & x) const{
	int retVal = 0;

	if(x >= 0){
		retVal = x % table.size();
	}else{
		retVal = table.size() + x;
	}

	return retVal;
}

bool HopScotchHash::shiftDown(int home, int open, HashEntry & x){ //We know open is too far from home initially

	//cout << "SHIFT DOWN CALLED WITH: " << x.item << endl;
	//cout << "HOME: " << home << " OPEN: " << open << endl;
	if((open - home) < MAX_DIST){ //Base Case -> open is close enough to home
		table[open].item = x.item;
		table[open].isActive = true;
		table[home].hop |= 1 << (3-(open - home));
		//cout<<"BASE CASE" << endl;
		//printContent();

		return true;

	}else{ //Do recursive stuff -> open is too far from home

		for(int i = 3; i > 0; i--){
			if(((table[open-i].hop >> 3) & 1) == 1){ //Then we can swap - put x.item into the open-i spot
				HashEntry temp = table[open-i];
				table[open-i].item = table[open].item;
				table[open-i].hop &= ~(1 << 3);
				table[open-i].hop |= 1 << (3-i);
				table[open].item = temp.item;
				open = open - i;
				//printContent();
				shiftDown(home, open, x);

				if((open - home) < MAX_DIST){ //Leave the for loop to prevent extra shifting of items
					return true;
				}
			}
		}
	}
}

bool HopScotchHash::insert(HashEntry & x){
	int temp = myHash(x.key); //x's home

	if(table[temp].isActive == false){ //If the home is free
		table[temp] = x;
		table[temp].hop = 8;
		table[temp].isActive = true;
		//printContent();
		return true;
	}else{ //Home is not free, find next open spot, call shiftDown
		int open = temp; //Open will be set to distance from home to the next free spot after the for loop

		for(; open < table.size(); open++){
			if(table[open].isActive == false){
				break;
			}
		}

		table[open].isActive = true;
		shiftDown(temp, open, x);

		return true;
	}

	return false;
}

void HopScotchHash::printContent(){
	cout << "Index \t Item \t Hop" << endl;

	for(int x = 0; x < table.size(); x++){
		bitset<4> temp(table[x].hop);
		cout << x << "\t" << table[x].item << "\t" << temp << endl;
	}
}