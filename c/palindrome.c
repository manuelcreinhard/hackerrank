
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
void findPalind(char *arr)
{
     
    int flag = 0;
    int map[27];
    int i;
    for(i=0;i<27;i++){
		map[i] = 0;
	}
    int impair = 0;
    char temp = *arr;
    int pos;
    while(temp != '\0'){
        pos = temp - 97;
        map[pos]++;
        if(map[pos]%2 == 0){
            impair--;
        } else {
            impair++;
        }
        
        temp = *(++arr);
    }
    if(impair > 1){
        flag = 1;
    }
    // Find the required answer here. Print Yes or No at the end of this function depending on your inspection of the string
    if (flag==0){
        printf("YES\n");
	} else {
        printf("NO\n");
	}
    
    return;
}
int main() {

    char arr[100001];
    scanf("%s",arr);
    findPalind(arr);
    return 0;
}
