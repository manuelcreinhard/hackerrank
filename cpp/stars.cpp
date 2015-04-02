#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	int points; cin >> points;
	map<long,map<long,int> > map_;
	long x,y;
	unsigned int v;
	unsigned long total = 0;
	while(points--){
		cin >> x >> y >> v;
		map_[x][y] = v;
		total += v;
	}
	map<long,map<long,int> >::iterator x_it;
	map<long,int>::iterator y_it;
	unsigned long temp = 0;
	vector<unsigned long> vect;
	for(x_it = map_.begin();x_it != map_.end();x_it++){
		for(y_it = x_it->second.begin(); y_it != x_it->second.end();y_it++){
			cout << "x: " << x_it->first << " y: " << y_it->first << " = " << y_it->second << " ";
			temp += y_it->second;
		}
		cout << endl;
		vect.push_back(temp);
	}
	vector<unsigned long>::iterator it;
	for(it = vect.begin(); it != vect.end(); it++){
		cout << *it << " diff " << total - *it << endl;
	}
	cout << "total: " << total << endl;
    return 0;
}
