using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "telephone.h"

#define PHONE_NUMBER_LENGTH 7

int main(){
	int phoneNum[PHONE_NUMBER_LENGTH] = {1,1,1,1,2,2,2};
	PrintTelephoneWords(phoneNum);
	return 1;
}


char getCharKey(int telephoneKey, int place){
	if(telephoneKey == 0){
		return '0';
	} else if(telephoneKey == 1){
		return '1';
	}
	return (49 + (telephoneKey-2)*3 + place-1) + '0';
}

void PrintTelephoneWords(int phoneNum[]){
	char result[PHONE_NUMBER_LENGTH+1];
	result[PHONE_NUMBER_LENGTH] = '\0';
	DoPrintTelephoneWords(phoneNum,0,result);
}

void DoPrintTelephoneWords(int phoneNum[], int cDigit, char result[]){
	int i;
	if(cDigit == PHONE_NUMBER_LENGTH){
		printf("%s\n",result);
		return;
	}
	for(i = 1;i<=3;i++){
		result[cDigit] = getCharKey(phoneNum[cDigit],i);
		DoPrintTelephoneWords(phoneNum,cDigit+1,result);
		if(phoneNum[cDigit] == 0 || phoneNum[cDigit] == 1)
			return;
	}
}
