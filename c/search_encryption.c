#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
	char *line = NULL;
	char nospace[81];
	size_t size;
    char t;
    int count = 0;
    int i = 0;
    if (getline(&line, &size, stdin) == -1) {
       if (getline(&line, 0, stdin) == -1) {
		}
	} else {
		while((t = line[i]) != '\0'){
			if(t != ' '){
				nospace[count] = line[i];
				count++;
			}
			i++;
		}
		nospace[count] = '\0';
		double sq = sqrt(count);
		int sq_f = floor(sq);
		int sq_c = ceil(sq);
		int r,c;
		if(sq_f * sq_c >= count){
			c = sq_c;
			r = sq_f;
		} else {
			c = sq_c;
			r = sq_c;
		}
		int i, j;
		for(i = 0; i < c; i++){
			for(j = 0; j < r;j++){
				if(j*c+i < count-1){
					printf("%c",nospace[j*c+i]);
				}
			}
			printf(" ");
		}
	}
	
	
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
