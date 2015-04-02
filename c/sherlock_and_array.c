#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calcSums(int * numbers, int count){
	unsigned long left = 0;
	unsigned long right = 0;
	//unsigned long total;
	int i;
	for(i=0;i<count;i++){
		right+=numbers[i];
	}
	for(i = 0; i < count; i++){
		if(i>0){
			left+=numbers[i-1];
		}
		right -= numbers[i];
		if(left == right){
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}

int main() {
	int cases;
	scanf("%d",&cases);
	int i;
	for(i = 0; i < cases;i++){
		int count;
		scanf("%d",&count);
		int numbers[count];
		int i = 0;
		while(i<count){
			scanf("%d",&numbers[i]);
			i++;
		}
			calcSums(numbers,count);
	}
	
    return 0;
}

