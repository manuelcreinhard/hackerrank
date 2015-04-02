#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int toNumber(char a[]) {
  int c, sign, offset, n;
 
  if (a[0] == '-') {
    sign = -1;
  }
 
  if (sign == -1) {
    offset = 1;
  }
  else {
    offset = 0;
  }
 
  n = 0;
 
  for (c = offset; a[c] != '\0'; c++) {
    n = n * 10 + a[c] - '0';
  }
 
  if (sign == -1) {
    n = -n;
  }
 
  return n;
}
int permut(int n){
	int perm = 0;
	int t;
	for(t=n;t>0;t--){
		perm+=t;
	}
	printf("%d elements give %d permutations\n",n,perm);
	return perm;
}


int main() {
	int total = 0;
	int values;
	scanf("%d\n",&values);
	char *arr = malloc(sizeof(char)*100000);
    scanf("%[^\n]s",arr);
    char temp[100];
    int last = 0;
    int count = 0;
    int pos = 0;
    do{
		if((*arr != ' ') && (*arr != '\0')){
			temp[pos++] = *arr; 
		} else {
			temp[pos] = '\0';
			int n = toNumber(temp);
			printf("number: %d\n",n);
			pos = 0;
			if (n>last){
				count++;
			} else {
				int t_count = permut(count);
				total += t_count;
				count = 1;
			}
			last = n;
		}
	} while(*(arr++) != '\0');
	total += permut(count);
	printf("%d\n",total);
    return 0;
}

