
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int cases;
    scanf("%d",&cases);
    int px,qx,py,qy;
    int x2,y2;
    while(cases--){
		scanf("%d %d %d %d",&px,&py,&qx,&qy);
		x2 = 2*qx - px;
		y2 = 2*qy - py;
		printf("%d %d\n",x2,y2);
	}
    return 0;
}
