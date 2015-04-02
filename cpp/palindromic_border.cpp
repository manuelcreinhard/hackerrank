#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map<string,int> substringsn2(string str){
	map<std::string,int> subs;
	string temp; 
	for(std::string::size_type i = 0; i < str.size(); i++) {
		for(std::string::size_type j = 2; j <= str.size() - i; j++) {
			temp = str.substr(i,j);
			
			//cout << "Temp: " << temp << endl;
			if(!subs.count(temp)){
				subs[temp] = 1;
			} else {
				subs[temp]++;
			}
		}
	}
	
	
	
	return subs;
}

bool isPalind(string one, string two){
	for(std::string::size_type i = 0; i < one.size(); i++) {
		//cout << "Comparing: " << one[i] << " and: " << two[one.size() - i - 1] << endl;
		if(one[i] != two[one.size() - i - 1]){
			//cout << "Returning false" << endl;
			return false;
		}
	}
	//cout << "Returning true" << endl;
	return true;
}

int palindBorders(string str){
	string left,right;
	//cout << "P borders: " << str << endl;
	int count = 0;
	for(std::string::size_type i = 1; i < str.size(); i++) {
			left  = str.substr(0,i);
			right = str.substr(str.size() - i ,i);
			//cout << "Left: " << left << " Right: " << right << endl;
			if(isPalind(left,right) && left.compare(right) == 0){
				//cout << "Count ++ " << endl;
				count++;
			}
	}
	//cout << "Count: " << count << endl;
	return count;
}

int main() {
	string str;
	cin >> str;
	int count = 0;
	map<string,int> subs = substringsn2(str);
	map<string,int>::iterator it;
	for(it=subs.begin();it != subs.end();it++){
		//cout << it->first << " => " << it->second << endl;
		count += palindBorders(it->first) * it->second;
	}
	cout << "Count: " << count << endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
