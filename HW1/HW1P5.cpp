/*

	Name: Nikhil Gupta
	BU e-mail: nikhilgu@bu.edu

*/

#include <iostream>

using namespace std;

void strXpos(char *dest, const char *src){
	if(src[0] == '\0'){
		return;
	}else if(src[1] == '\0'){
		dest[0] = src[0];
		dest[1] = src[1];
		return;
	}else{
		dest[0] = src[1];
		dest[1] = src[0];
		strXpos(dest + 2, src + 2);
	}

}