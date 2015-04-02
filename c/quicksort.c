#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void quickSort(int ar_size, int *  ar) {
	if(ar_size <= 1){
		return;
	} else if(ar_size == 2){
		if(ar[0] > ar[1]){
			int temp = ar[1];
			ar[1] = ar[0];
			ar[0] = temp;
		}
		printf("%d %d\n",ar[0],ar[1]);
		return;
	}
    int i=1,j = 0,k = 0;
    int p = ar[0];
    int left[ar_size];
    int right[ar_size];
    while(i < ar_size){
		if(ar[i] > p){
			right[j++] = ar[i];
		} else {
			left[k++] = ar[i];
		}
		i++;
	}
	quickSort(k,left);
	quickSort(j,right);
	i = 0;
	while(i < k){
		ar[i] = left[i];
		i++;
	}
	ar[i++] = p;
	while(i < ar_size){
		ar[i] = right[i-k-1];
		i++;
	}
	i = 0;
	while(i < ar_size){
		printf("%d ",ar[i]);
		i++;
	}
	printf("\n");
}
int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

quickSort(_ar_size, _ar);
   
   return 0;
}
