#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
vector<int> ind_first;
vector<int> ind_second;
map<int,int> indices;
//vector<int> indices;


void getIndexes(string &str, char first, char second){
	for(std::string::size_type i = 0; i < str.size(); i++) {
		if(str[i] == first){
			//cout << "Pushing back " << i << " into first" << endl;
			ind_first.push_back(i);
		}
		if(i > 0 && str[i] == second){
			//cout << "Pushing back " << i << " into second" << endl;
			ind_second.push_back(i);
		}
	}
}

void findMatches(string &str,string &vir){
	vector<int>::iterator it;
	unsigned int count;
	int mismatch;
	for(it = ind_first.begin();it != ind_first.end();it++){
		mismatch = 0;
		count = 0;
		if(*it+vir.length() > str.length()){
			//cout << "Length no more..." << *it << endl;
			continue;
		}
		while(count < vir.length()){
			//cout << "Comparing " << vir[count] << " and " << str[*it+count] << endl;
			//cout << "Count: " << count << " iterator: " << *it << endl;
			if(vir[count] != str[*it+count] && ++mismatch > 1){
				break;
			}
			count++;
		}
		if(mismatch <= 1){
			indices[*it] = *it;
		}
	}
	//cout << "Second list " << endl;
	for(it = ind_second.begin();it != ind_second.end();it++){
		mismatch = 0;
		count = 0;
		if(*it+vir.length() - 1 > str.length()){
			//cout << "Length second no more..." << *it << endl;
			continue;
		}
		while(count < vir.length()){
			//cout << "Comparing " << vir[count] << " and " << str[*it+count-1] << endl;
			//cout << "Count: " << count << " iterator: " << *it << endl;
			if(vir[count] != str[*it+count-1] && ++mismatch > 1){
				break;
			}
			count++;
		}
		if(mismatch <= 1){
			indices[*it - 1] = *it - 1;
		}
	}
}

void printMatches(){
	//cout << "Printing matches..." << endl;
	map<int,int>::iterator it;
	for(it = indices.begin(); it != indices.end(); it++){
		cout << it->first << " ";
	}
	cout << endl;
}

int main() {
    int cases; cin >> cases;
    string virus;
    string human;
    while(cases--){
		ind_first = vector<int>();
		ind_second = vector<int>();
		indices = map<int,int>();
		cin >> human;
		cin >> virus;
		if(virus.length() > 1){
			getIndexes(human,virus[0], virus[1]);
			findMatches(human,virus);
			printMatches();
		} else {
			for(unsigned int i = 0; i < human.length(); i++){
				cout << i << " ";
			}
			cout << endl;
		}
	}  
    return 0;
}
