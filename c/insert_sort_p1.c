#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *  ar) {
	int i,j;
	for(i = 2;i<ar_size;i++){
		for(j = i;j>1 && ar[j] < ar[j-1];j--){
			int temp =ar[j];
			ar[j] = ar[j-1];
			ar[j-1] = temp;
		}
	}
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

