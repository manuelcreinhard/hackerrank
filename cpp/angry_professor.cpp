#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int cases; cin >> cases;
	int n,k,t;
	while(cases--){
		cin >> n >> k;
		while(n--){
			cin >> t;
			if(t<=0){
				k--;
			}
		}
		if(k<=0){
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
    return 0;
}

