#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *  ar) {
	int i,j;
	int save = ar[ar_size-1];
	i = ar_size - 1;
	do{
		if(i==0){
			ar[0] = save;
		}		
		else if(save<ar[i-1]){
			ar[i] = ar[i-1];
			
		} else {
			ar[i] = save;
		}
		for(j=0;j<ar_size;j++){
			printf("%d ",ar[j]);
		}
		printf("\n");
		i--;
	} while(i>=0 && save<ar[i]);
}
int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

insertionSort(_ar_size, _ar);
   
   return 0;
}


