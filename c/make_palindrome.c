
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void makePalind(char *arr){
	char *ptr = arr;
	char *endptr = arr;
	int length = 0;
	char save = *ptr;
	while(save != '\0'){
		save = *(++ptr);
		length++;
	}
	//char *endptr = arr;
	//printf("length: %d\n",length);
	//int i;
	int impair = length%2;
	
	ptr = arr;
	endptr += length;
	endptr--;
	int count = 0;
	while(ptr != endptr && count<(length/2+impair)){
		//printf("start:%c\nend: %c\n",*ptr,*endptr);
		if(*ptr != *endptr){
			char *temp = ptr;
			temp++;
			if(*temp == *endptr){
				printf("%d\n",count);
				return;
			} else {
				printf("%d\n",length-count-1);
				return;
			}
		}
		ptr++;
		endptr--;
		count++;
	}
	printf("-1\n");
}
//int argc, char *argv[]
int main() {
	int loops;
	scanf("%d",&loops);
	while(loops-->0){
		//char arr[33721];
		
		char *arr = malloc(sizeof(char)*100000);
		scanf("%s",arr);
		makePalind(arr);
		free(arr);
	}
	
	//makePalind(argv[1]);
    return 0;
}
