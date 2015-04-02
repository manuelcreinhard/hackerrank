#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() 
{
    int n; cin >> n;
    for(int i = 0; i < n;i++){
		int s,k; cin >> s >> k;
		vector<int> a;
		vector<int> b;
		for(int j = 0; j < s; j++)
		{
			int e; cin >> e;
			a.push_back(e);
		}
		for(int j = 0; j < s; j++)
		{
			int e; cin >> e;
			b.push_back(e);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(), std::greater<int>());
		bool r = true;
		for(int j = 0; j < s; j++){
			if(a[j] + b[j] < k){
				r = false;
				break;
			}
		}
		if(r){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    return 0;
}
