#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;


int maxSub(vector<int> & list, map<int,map<int,int> > & mymap, int i, int j){
	if(j-i < 0){
		return 0;
	}
	if(i == j){
		return list[i];
	}
	if(mymap.find(i) != mymap.end()){
		
		if(mymap[i].find(j) != mymap[i].end()){
			return mymap[i][j];
		}
	}
	int x = maxSub(list,mymap,i,j-1);
	int y = maxSub(list,mymap,i+1,j);
	x = max(x, x + list[j]);
	y = max(y, y + list[i]);
	mymap[i][j] = max(x,y);
	return mymap[i][j];
}

int maxSubCont(vector<int> & list, map<int,map<int,int> > & mymap){
	int mymax = INT_MIN;
	for(int i = list.size() - 1; i >= 0; i--){
		for(unsigned int j = i; j < list.size(); j++){
			mymap[i][j] = mymap[i][j-1] + list[j];
			if(mymap[i][j] > mymax){
				mymax = mymap[i][j];
			}
		}
	}
	return mymax;
}

int main() {
    int cases; cin >> cases;
    int n,t;
    while(cases--){
		cin >> n;
		vector<int> list;
		for(int i = 0; i < n; i++){
			cin >> t;
			list.push_back(t);
		}
		map<int,map<int,int> > mymap;
		map<int,map<int,int> > mymapcont;
		int maxV = maxSub(list, mymap, 0,n-1);
		int maxC = maxSubCont(list,mymapcont);
		cout << maxC << " " << maxV << endl;
		//for_each(list.begin(),list.end(),print);
	}
    return 0;
}
