#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int cases;
    int t = scanf("%d",&cases);
    unsigned long n,k;
    while(cases--){
		t = scanf("%lu %lu",&n,&k);
		long long p_sq = (long long)n*n - (long long)4*n*k;
		//printf("presqrt: %lld\n", p_sq);
		if(p_sq < 0){
			printf("%lu\n", n - 1);
			continue;
		}
		//printf("sqrt: %f\n",sqrt(p_sq));
		long double r_2 = (long double)-1*n - (long double)sqrt(p_sq);
		long double r_1 = (long double)-1*n + (long double)sqrt(p_sq);
		//printf("limits: %Lf %Lf\n", r_1,r_2);
		r_2/=-2;
		r_1/=-2;
		//printf("limits: %Lf %Lf\n", r_1,r_2);
		if(r_1 == r_2){
			printf("%lu\n",n - 1);
			continue;
		}
		unsigned long count = 0;
		count += (unsigned long)floor(r_1);
		count += (unsigned long)n - ceil(r_2);
		printf("%lu\n",count);
	}  
    return 0;
}
