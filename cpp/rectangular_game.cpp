#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int values;
	scanf("%d",&values);
	unsigned int x,y;
	unsigned int sx,sy;
	scanf("%d %d",&sx,&sy);
	values--;
	while(values--){
		scanf("%d %d",&x,&y);
		if(x < sx){
			sx = x;
		}
		if(y < sy){
			sy = y;
		}
	}
	unsigned long r = (unsigned long)sx * (unsigned long)sy;
	printf("%lu\n",r);
    return 0;
}
