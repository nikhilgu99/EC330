/*
*	Name: Nikhil Gupta
*	BU ID: U86132587
*/

#include <iostream>
#include <vector>

using namespace std;

void MaxIncSeq (int *nums, int len){ // O(n*log(n))

	vector<int> list(len); 
	vector<int> temp(len);

	int a, b, count = 0;
	list.push_back(0);

	for (int i = 1; i < len; i++) { //Must go all elements at some point, therefore "n" time

		if (nums[list.back()] < nums[i]){ //If next element is bigger than biggest in list, add to back of list
			temp[i] = list.back();
			list.push_back(i);
			count++;
		}

		for (a = 0, b = list.size() - 1; a < b;){ //Binary search on list, thereforce "log(n)" time instead of "n" time
			int c = (a + b) / 2;
			if (nums[list[c]] < nums[i]){ 
				a=c+1;
			}else{ 
				b=c;
			}
		}

		if (nums[i] < nums[list[a]]){ // Update list if next (i) value is smaller then last value from list 
			if (a > 0){
				temp[i] = list[a - 1];
			}
				list[a] = i;
		}	
	}

	for (a = list.size(), b = list.back(); a--; b = temp[b]){ //Put values list vector from temp, which are indices of elements in array nums
		list[a] = b;
	}

	for (int i = list.size() - (count + 1); i < list.size(); i++){ // Print out the values in correct format
		cout << nums[list[i]] << " ";
	}
}
