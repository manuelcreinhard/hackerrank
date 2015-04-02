#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void calcOptimized(unsigned int * a, unsigned int * b, unsigned int * c, int n, int m){
	//printf("started calc optimized...\n");
	int i,j;
	for(i=0;i<m;i++){
		//printf("i: %d\n",i);
		for(j=b[i];j<=n;j+=b[i]){
			//printf("j: %d\n",j);
			
			//printf("a[j]: %d\n",a[j]);
			//printf("b: %d\n",b[i]);
			//printf("c: %d\n",c[i]);
			a[j-1] *= c[i];
			//printf("a[j]: %d\n",a[j]);
		}
	}
	for(i = 0; i < n;i++){
		printf("%d ",a[i]%1000000007);
	}
}

int main() {
	int m,n;
	scanf("%d %d",&n,&m);
	unsigned int a[n];
	unsigned int b[m];
	unsigned int c[m];
	int i;
	//printf("getting lists...a\n");
	for(i = 0; i < n;i++){
		scanf("%d",&a[i]);
	}
	//printf("getting lists...b\n");
	for(i = 0; i < m;i++){
		scanf("%d",&b[i]);
	}
	//printf("getting lists...c\n");
	for(i = 0; i < m;i++){
		scanf("%d",&c[i]);
	}
	//printf("finished getting lists...\n");
	calcOptimized(a,b,c,n,m);
    return 0;
}


