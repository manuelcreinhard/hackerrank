#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
int lonelyinteger(int a_size, int* a) {
	int map[100];
	int i = 0;
	for(i = 0; i < a_size; i++){
		int temp = *a;
		map[temp-1]++;
		printf("%d\n",map[temp]);
		a++;
	}
	for(i=0;i< a_size;i++){
		if(map[i] == 1){
			printf("Res: %d\n",i+1);
			return i+1;
		}
	}
	
return 0;
}
int main() {
    int res;
    
    int _a_size, _a_i;
    scanf("%d", &_a_size);
    int _a[_a_size];
    for(_a_i = 0; _a_i < _a_size; _a_i++) { 
        int _a_item;
        scanf("%d", &_a_item);
        
        _a[_a_i] = _a_item;
    }
    
    res = lonelyinteger(_a_size, _a);
    printf("%d", res);
    
    return 0;
}

//int lonelyinteger(int size, int *elements){
    //int map[] = int[100];
    //for(int i = 0; i < size; i++){
    //    int temp = *elements;
        //map[temp]++;
    //    elements++;
    //}
//    return 1;
//}
