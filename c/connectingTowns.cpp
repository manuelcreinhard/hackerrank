#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int cases;
    cin>>cases;
    while(cases > 0)
    {
        int towns;
        int *routes;
        int res = 1;
        cin>>towns;
        routes  = new int[towns-1];
        for(int i=0;i<towns-1;i++){
            cin>>routes[i];
		}
        for(int i=0;i<town-1;i++) {
			   res *= routes[i];
               res = ans%1234567;
           }
         cout<<ans<<"\n";
         cases--;
    }
    return 0;
}
