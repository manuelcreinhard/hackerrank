#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

vector<int> coins;
map<int,int> change;
int makeChange(int n){
	if(n==0){
		return 1;
	} else if(n < 0){
		return 0;
	}
	change[n] = 0;
	for(vector<int>::iterator it = coins.begin(); it != coins.end() && *it <= n; ++it){
		if(*it == n){
			change[n] = 1;
		}
	}
	change[n] += makeChange(n-1);
	return change[n];
}
int main() {
	int n, m; cin >> n >> m;
	int t;
	while(m--){
		cin >> t;
		coins.push_back(t);
	}
	sort(coins.begin(),coins.end());
	int result = makeChange(n);
    cout << result << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
