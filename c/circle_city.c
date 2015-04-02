#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void isProtected(int r, int k){
	//printf("isProtected: rad %d with %d\n",r,k); 
	unsigned long y;
	//int x = r;
	unsigned long rsqr = r * r;
	//printf("rsqr: %i\n",rsqr);
	int count = 0;
	int c1=0;
	int c3=0;
	unsigned long temp;
	for(y = 1; y < rsqr;y++){
		if(r%y != 0){
			continue;
		}
		temp = r/y;
		if(temp%4 == 1){
			c1++;
		} else if(temp%4 == 3){
			c3++;
		}
	}
	count = 4*(c1-c3);
	if(count <= k){
		printf("possible\n");
	} else {
		printf("impossible\n");
	}
	printf("Count: %d    c1: %d    c3: %d\n",count,c1,c3);
}


int main() {
	int loops = 0, r, k;
	scanf("%d",&loops);
	//printf("Cases: %d\n",loops);
	while(loops>0){
		scanf("%d %d",&r,&k);
		isProtected(r,k);
		loops--;
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
