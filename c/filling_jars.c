#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int m;
	int n;
	scanf("%d %d",&n,&m);
	int i;
	unsigned int total = 0;
	unsigned int s,e,c;
	for(i = 0; i < m;i++){
		scanf("%d %d %d",&s,&e,&c);
		total+= (e-s+1)*c;
	}
	double a = total/n;
	
	printf("%.0lf\n",floor (a));
	return 0;
}
