#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int p;
	int t;
	scanf("%d %d",&p,&t);
	int topics[t];
	int i,j;
	for(i = 0; i < t; i++){
		topics[i] = 0;
	}
	int people[p];
	for(i = 0; i < p; i++){
		scanf("%i",&people[i]);
	}
	int temp;
	int ones;
	for(i = 0; i < p - 1; i++){
		for(j = i + 1; j < p; j++){
			temp = people[i] | people[j];
			ones = 0;
			printf("Temp: %d\n",temp);
			while(temp > 0){
				ones += temp&1;
				temp/=2;
			}
			printf("Ones: %d\n",ones);
			topics[temp]++;
		}
	}
	for(i=t-1; i>=0; i--){
		if(topics[i] > 0){
			printf("%d\n",i);
			printf("%d\n",topics[i]);
			break;
		}
	}
	return 0;
}

