#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void anagram(char *arr){
	char *ptr = arr;
	int length = 0;
	char save = *ptr;
	while(save != '\0'){
		save = *(++ptr);
		length++;
	}
	if(length%2 == 1){
		printf("-1\n");
		return;
	}
	ptr = arr;
	char *ptr2 = arr;
	ptr2+=length/2;
	int dist = 0;
	int map1[27];
	int map2[27];
	int i;
	for(i=0;i<27;i++){
		map1[i]=0;
		map2[i]=0;
	}
	while(*ptr2 != '\0'){
		map1[(int)(*ptr-'a')]++;
		map2[(int)(*ptr2-'a')]++;
		ptr++;
		ptr2++;
	}
	for(i=0;i<27;i++){
		int temp = map1[i] - map2[i];
		if(temp < 0){
			temp*=-1;
		}
		dist+=temp;
	}
	dist/=2;
	printf("%d\n",dist);
}

int main() {
	int loops;
	scanf("%d",&loops);
	while(loops-->0){
		//char arr[33721];
		
		char *arr = malloc(sizeof(char)*100000);
		scanf("%s",arr);
		anagram(arr);
		free(arr);
	}
	
	//makePalind(argv[1]);
    return 0;
}
