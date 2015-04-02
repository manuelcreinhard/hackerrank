using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "recursion.h"


int main(){
	char str[] = "wxyz";
	cout << "Permute:\n";
	permute(str);
	cout << "Combine:\n";
	comb(str);
	return 1;

}
int permute(char inString[]){
	int length, i, *used;
	char *out;
	length = strlen(inString);
	out = (char *)malloc(length+1);
	if(!out)
		return 0;
		
	out[length] = '\0';
	used = (int *)malloc(sizeof(int) * length);
	if(!used)
		return 0;
	for(i=0;i<length;i++){
		used[i] = 0;
	}
	
	doPermute(inString,out,used,length,0);
	free(out);
	free(used);
	return 1;
}

void doPermute(char in[], char out[], int used[], int length, int rLvl){
	int i;
	if(rLvl == length){
		printf("%s\n",out);
		return;
	}
	for(i = 0; i < length; i++){
		if(used[i])
			continue;
			
		out[rLvl] = in[i];
		used[i] = 1;
		doPermute(in,out,used,length,rLvl+1);
		used[i] = 0;
	}
}

int comb(char inString[]){
	int length;
	char *out;
	length = strlen(inString);
	out = (char *)malloc(length+1);
	if(!out)
		return 0;
	doComb(inString,out,length,0,0);
	free(out);
	return 1;
}

void doComb(char in[], char out[], int length, int rLvl,int start){
	int i;
	for(i = start; i < length; i++){
		out[rLvl] = in[i];
		out[rLvl+1] = '\0';
		printf("%s\n",out);
		if(i<length - 1)
			doComb(in,out,length,rLvl+1,i+1);
	}
}

void bla(void* var){
	
}
