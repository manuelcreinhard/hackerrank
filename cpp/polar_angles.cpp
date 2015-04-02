#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const double PI =  3.1415926535897932385;

int main() {
    int values; cin >> values;
    double x,y;
    map<double,map<double,vector<pair<double, double> > > > map_;
    while(values--){
		cin >> x >> y;
		double a = atan2(y,x) * 180 / PI;
		if(a < 0){
			a += 360;
		}
		double h = sqrt(x*x + y*y);
		map_[a][h].push_back(make_pair(x,y));
	}
	map<double,map<double,vector<pair<double, double> > > >::iterator angles;
	map<double,vector<pair<double, double> > >::iterator hyp;
	vector<pair<double, double> >::iterator pairs;
	for(angles = map_.begin();angles != map_.end();angles++){
		for(hyp = angles->second.begin();hyp != angles->second.end();hyp++){
			for(pairs = hyp->second.begin();pairs != hyp->second.end();pairs++){
				cout << pairs->first << " " << pairs->second << endl;
			}
		}
	}
    return 0;
}
