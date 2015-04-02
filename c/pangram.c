

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
void isPangram(char *arr){
	char save = *arr;
	int map[26];
	int i;
	for(i=0;i<26;i++){
		map[i]=0;
	}
	int need = 26;
	int pos;
	while(save != '\0'){
		pos = save - 'A';
		if(pos>26){
			pos = save - 'a';
		}
		if(save != ' '){
			map[pos]++;
		}
		if(map[pos] == 1){
			need--;
			if(need == 0){
				printf("pangram");
				return;
			}
		}
		save = *(++arr);
	}
	printf("not pangram");
}
int main() {

    char arr[100001];
    scanf("%[^\n]s",arr);
    isPangram(arr);
    return 0;
}
