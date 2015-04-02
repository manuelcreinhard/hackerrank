#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<string,int> map_;

void getSubstrings(string &str, int i, int j){
	//cout << "getSubstrings i: " << i << " j: " << j <<endl;
	if(j-i <= 0){
		//cout << "j-i <= 0, returning" << endl;
		return;
	}
	if(map_.find(str.substr(i, j-i)) != map_.end()){
		//cout << "Found entry. Returning... "<<endl;
		return;
	}
	map_[str.substr(i, j-i)] = 1;
	getSubstrings(str,i,j-1);
	getSubstrings(str,i+1,j);
}

int main() {
	int cases;cin>>cases;
	string str;
	while(cases-- > 0){
		map_ = unordered_map<string,int>();
		cin >> str;
		getSubstrings(str,0,str.length());
		vector<string> v;
		unordered_map<string,int>::iterator it;
		for(it=map_.begin(); it != map_.end();it++){
			v.push_back(it->first);
			
		}
		sort(v.begin(),v.end());
		vector<string>::iterator vit;
		int k;
		cin >> k;
		for (vit=v.begin(); vit!=v.end(); vit++){
			if((k - (*vit).length()) <= 0){
				cout << (*vit)[k-1] << endl;
				break;
			}
			k -= (*vit).length();
		}
		//cout << str << endl;
	}
    return 0;
}

