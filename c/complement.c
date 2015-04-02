#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int size;
    unsigned int value;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%d", &size);
    int i = 0;
    for(i = 0; i < size; i++){
        scanf("%i", &value);
        unsigned int comp = ~value;
        printf("%u\n",comp);
    }
    return 0;
}
