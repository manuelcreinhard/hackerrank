#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void getGems(char *arr,int *gems){
	int temp[27];
	int i;
	for(i=0;i<27;i++){
		temp[i] = 0;
	}
	while(*arr != '\0'){
		temp[*(arr++)-'a'] = 1;
	}
	for(i=0;i<27;i++){
		gems[i] &= temp[i];
	}
}

int main() {
	int loops;
	scanf("%d",&loops);
	int gems[27];
	int j;
	for(j=0;j<27;j++){
		gems[j] = 1;
	}
	char *arr;
	int i = 0;
	while(i<loops){
		arr = malloc(sizeof(char)*100000);
		scanf("%s",arr);
		getGems(arr,gems);
		i++;
	}
	int k;
	int count;
	for(k=0;k<27;k++){
		count += gems[k];
//		if(gems[k] == 1){
//			printf("%c",k+'a');
//		}
	}
	printf("%d\n",count);
    return 0;
}
