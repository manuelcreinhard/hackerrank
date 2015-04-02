#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	map<int, int> map_;
	int n,m,temp;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&temp);
		if(!map_.count(temp)){
			map_[temp] = 1;
			continue;
		}
		map_[temp]++;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d",&temp);
		if(!map_.count(temp)){
			map_[temp] = -1;
			continue;
		}
		map_[temp]--;
	}
	for (std::map<int,int>::iterator it=map_.begin(); it!=map_.end(); it++){
		if(it->second == 0){
			continue;
		}
		printf("%d ",it->first);
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
