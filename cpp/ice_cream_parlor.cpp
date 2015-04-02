#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
	int cases; cin >> cases;
	unsigned int m,n,t;
	unordered_map<int,unsigned int> map_;
	unordered_map<int,unsigned int>::iterator it;
	int i = 1;
	while(cases--){
		cin >> m >> n;
		while(n--){
			cin >> t;
			map_[t] = i;
			i++;
		}
		for(it = map_.begin(); it != map_.end(); it++){
			if(map_.find(m - it->first) != map_.end()){
				cout << it->second << " " << map_[m - it->first] << endl;
				break;
			}
		}
		
	}
	
    return 0;
}
