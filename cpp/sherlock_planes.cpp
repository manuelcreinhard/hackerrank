#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void getVector(int p[], int q[], int * r){
	for(int i = 0; i < 3; i++){
		r[i] = q[i] - p[i];
	}
}


void crossProd(int a[], int b[], int * r){
	r[0] = a[1]*b[2] - a[2] * b[1];
	r[1] = a[0]*b[2] - a[2] * b[0];
	r[2] = a[0]*b[1] - a[1] * b[0];
}

int dotProd(int a[], int b[]){
	int r = 0;
	for(int i = 0; i < 3; i++){
		r+=a[i]*b[i];
	}
	return r;
}

int main() {
    int cases;
    scanf("%d",&cases);
    int points[4][3];
    while(cases--){
		for(int i = 0; i < 4; i++){
			scanf("%d %d %d", &points[i][0],&points[i][1],&points[i][2]);
		}
		int v1[3];
		getVector(points[0],points[1],v1);
		int v2[3];
		getVector(points[0],points[2],v2);
		int cp[3];
		crossProd(v1,v2,cp);
		int v3[3];
		getVector(points[0],points[3],v3);
		if(dotProd(cp,v3) == 0){
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
    return 0;
}


