#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void getflavors(int * flist, int flavors, int dollars){
	//printf("Looking for %d dollars in %d flavors\n",dollars,flavors);
	int i = flavors - 1;
	int j = 0;
		while(i >= 0){
			j = 0;
			while(j<flavors){
				//printf("%d %d\n",j,i);
				
				if(i == j){
					j++;
					continue;
				}
				if((flist[i] + flist[j]) == dollars){
					printf("%d %d\n",j+1,i+1);
					return;
				}
				j++;
			}
			i--;
		}
}

int main() {
	int loops = 0, dollars, flavors;
	scanf("%d",&loops);
	//printf("Cases: %d\n",loops);
	while(loops>0){
		scanf("%d",&dollars);
		scanf("%d",&flavors);
		int flist[flavors];
		int i = 0;
		while(i<flavors) {
			scanf("%d",&(flist[i]));
			//printf("%d\n",flist[i]);
			i++;
		}
		getflavors(flist,flavors,dollars);
		loops--;
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
