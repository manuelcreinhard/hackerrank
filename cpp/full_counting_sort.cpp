#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
	unsigned long l; 
	map<unsigned long,vector<string> > map_;
	cin >> l;
    unsigned long ll = 0;
	int t;
	string s;
	while(ll<l){
		cin >> t >> s;
        if(ll >= l/2){
            map_[t].push_back(s);
        } else {
            map_[t].push_back("-");
        }
		
        ll++;
	}
	map<unsigned long,vector<string> >::iterator it;
	vector<string>::iterator sit;
	for(it = map_.begin(); it != map_.end(); it++){
		for(sit = it->second.begin(); sit != it->second.end();sit++){
			cout << *sit << " ";
		}
	}
	cout << endl;
    return 0;
}
