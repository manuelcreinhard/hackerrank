#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        int towns;
        int res = 1;
        int mod = 1234567;
        scanf("%d",&towns);
        unsigned int routes[towns-1];
        int i;
        for(i=0;i<towns-1;i++){
			scanf("%d",&routes[i]);
		}
        for(i=0;i<towns-1;i++) {
			printf("%d has %d routes\n",i,routes[i]);
			res *= routes[i];
			printf("res: %d\n",res);
         }
         int r = res%mod;
         printf("%d\n",r);
        
    }
    return 0;
}
