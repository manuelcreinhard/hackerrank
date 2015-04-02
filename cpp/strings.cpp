using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"

#define MAX_DIGITS_INT 10

int main(){
	char mystr[] = "Battle of the vowels: Hawaii vs. Gronzy";
	firstNonRepeated(mystr);
	
	cout << mystr<<"\n";
	cout << "FNR: " <<firstNonRepeated(mystr)<<"\n";
	char remove[] = "aeiou";
	removeChars(mystr,remove);
	cout << mystr<<"\n";
	
	char str[] = "piglet quantum";
	cout << str << "\n";
	reverseWords(str);
	cout << str << "\n";
	
	char wrds[] = "hello world";
	cout << wrds << "\n";
	reverseWordsSpecial(wrds);
	cout << wrds << "\n";
	
	char num[] = "12345";
	cout << num << "\n";
	cout << strToInt(num) << "\n";
	char fromNum[MAX_DIGITS_INT+2];
	int i = 0;
	intToStr(i,fromNum);
	cout << "intToStr: " << fromNum << "\n";
	return 1;
}

char firstNonRepeated(char str[]){
	char current = str[0];
	chr *chars[256];
	for(int i = 0; i < 256;i++){
		chars[i] = NULL;
	}
	int count = 0;
	while(current != '\0'){
		if(current-'0'> 0){
			if(chars[current-'0'] == NULL){
				chars[current-'0'] = (chr *) malloc(sizeof(chr));
				chars[current-'0']->pos = count;
				chars[current-'0']->count = 1;
				//cout << "Data: "<<current<<" int: "<< current-'0' <<"\n";
			} else{
				(chars[current-'0']->count)++;
			}
		}
		count++;
		current = str[count];
	}
	char fnr;
	int pos = -1;
	for(int i=0;i<256;i++){
		if(chars[i] != NULL){
			if(chars[i]->count == 1){
				if(pos == -1){
					pos = chars[i]->pos;
					fnr = (char)i+'0';
				} else if(pos>chars[i]->pos){
					pos = chars[i]->pos;
					fnr = (char)i+'0';
				}
			}
		}
	}
	return fnr;
}

void removeChars(char str[], char remove[]){
	int src, dst, removeArray[256];
	for(src = 0;src < 256; src++){
		removeArray[src] = 0;
	}
	src= 0;
	while(remove[src]){
		removeArray[remove[src]] = 1;
		src++;
	}
	src = dst = 0;
	do{
		if(!removeArray[str[src]]){
			str[dst++] = str[src];
		}
	} while(str[src++]);
}


int reverseWords(char str[]){
	char *buffer;
	int tokenReadPos, wordReadPos, wordEnd, writePos = 0;
	tokenReadPos = strlen(str)-1;
	buffer = (char *) malloc(tokenReadPos + 2);
	if(!buffer)
		return 0;
	while(tokenReadPos >= 0){
		if(str[tokenReadPos] == ' '){
			buffer[writePos++] = str[tokenReadPos--];
		} else {
			wordEnd = tokenReadPos;
			while(tokenReadPos >= 0 && str[tokenReadPos] != ' ' )
				tokenReadPos--;
			wordReadPos = tokenReadPos + 1;
			while(wordReadPos <= wordEnd){
				buffer[writePos++] = str[wordReadPos++];
			}
		}
	}
	buffer[writePos] = '\0';
	strcpy(str,buffer);
	free(buffer);
	return 1;
}

void reverseString(char str[], int start, int end){
	char temp;
	while(end>start){
		temp = str[end];
		str[end--] = str[start];
		str[start++] = temp;
	}
	return;
}

void reverseWordsSpecial(char str[]){
	int start = 0, end = 0, length;
	length = strlen(str);
	reverseString(str,start,length-1);
	while(end < length){
		if(str[end] != ' ') {
			start = end;
			while(end < length && str[end] != ' ' ){
				end++;
			}
			end--;
			reverseString(str,start,end);
		}
		end++;
	}
	return;
}

int strToInt(char str[]){
	int result = 0;
	int length = strlen(str);
	int nFlag = 0;
	if(str[0] == '-'){
		nFlag = 1;
	}
	for(int i = nFlag;i < length;i++){
		result*=10;
		result += str[i] - '0';
	}
	if(nFlag)
		result *= -1;
	return result;
}

void intToStr(int num, char str[]){
	int nFlag = 0, i = 0, j = 0;
	char temp[MAX_DIGITS_INT + 2];
	if(num < 0){
		num *= -1;
		nFlag = 1;
	}
	do{
		char tmp =(num % 10) + '0';
		temp[i++] = (num %10) + '0';
		num /= 10;
	}while(num);
	if(nFlag){
		temp[i++] = '-';
	}
	while(i>0){
		str[j++] = temp[--i];
	}
	str[j] = '\0';
}
