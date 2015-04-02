#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	int l; 
	map<int,int> map_;
	cin >> l;
	int t;
	while(l--){
		cin >> t;
		map_[t]++;
	}
	map<int,int>::iterator it;
	for(it = map_.begin(); it != map_.end(); it++){
		for(int i = 0; i < it->second;i++){
			cout << it->first << " ";
		}
	}
	cout << endl;
    return 0;
}

