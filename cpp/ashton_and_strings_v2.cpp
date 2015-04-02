#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
unordered_map<string,int> map_;
map<char,vector<int> > indexes;

void getIndexes(string &str){
	for(std::string::size_type i = 0; i < str.size(); i++) {
		indexes[str[i]].push_back(i);
	}
}


/*
void getSubstrings(string &str, int k){
	
	
	for(std::string::size_type i = 0; i < str.size(); i++) {
		for(int j = 0; j < str.size(); j++) {
			
		}	
	}
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
*/
int main() {
	int cases;cin>>cases;
	string str;
	while(cases-- > 0){
		map_ = unordered_map<string,int>();
		indexes = map<char,vector<int> >();
		cin >> str;
		getIndexes(str);
		map<char,vector<int> >::iterator ind_it;
		vector<int>::iterator v_it;
		for(ind_it = indexes.begin(); ind_it != indexes.end(); ind_it++){
			for(v_it = (*ind_it).second.begin(); v_it != (*ind_it).second.end(); v_it++){
				cout << *v_it;
			}
			cout << "\n";
		}
		
		for(char ch = 'a'; ch <= 'd'; ch++){
			for(v_it = indexes[ch].begin();v_it != indexes[ch].end(); v_it++){
				cout << str[*v_it] << endl;
			}
		}
		
		for(ind_it = indexes.begin(); ind_it != indexes.end(); ind_it++){
			for(v_it = (*ind_it).second.begin(); v_it != (*ind_it).second.end(); v_it++){
				cout << *v_it;
			}
			cout << "\n";
		}
		
		
		
		return 0;
		//getSubstrings(str,0,str.length());
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

