using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "endian.h"


int main(){
	if(Endianness()){
		cout << "Little-endian!\n";
	}
	return 1;
}

int Endianness(){
	union {
		int myInt;
		char sbyte;
	} endianTest;
	endianTest.myInt = 1;
	return endianTest.sbyte;
}
