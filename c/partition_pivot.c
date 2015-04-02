#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int ar_size, int *  ar) {
    int p = *ar;
    int l_one[ar_size];
    int l_two[ar_size];
    int i;
	int j = 0;
	int k = 0;
	for(i = 1;i<ar_size;i++){
		if(ar[i]<p){
			l_one[j++] = ar[i];
		} else {
			l_two[k++] = ar[i];
		}
	}
	l_one[j++] = p;
	for(i = j;i<ar_size;i++){
		l_one[i] = l_two[i-j];
	}
	for(i = 0;i < ar_size;i++){
		printf("%d ",l_one[i]);
	}

}
int main(void) {
   
   int _ar_size;
scanf("%d", &_ar_size);
int _ar[_ar_size], _ar_i;
for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
   scanf("%d", &_ar[_ar_i]); 
}

partition(_ar_size, _ar);
   
   return 0;
}
