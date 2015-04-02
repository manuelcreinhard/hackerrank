#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int cases;cin >> cases;
    string str;
    int index;
    while(cases--){
		cin >> str;
		index = -1;
		for(std::string::size_type i = 0; i < str.size()/2; i++) {
			if(str[i] != str[str.size() - 1 - i]){
				if(str[i+1] == str[str.size() - 1 - i]){
					index = i;
				} else {
					index = str.size() - 1 -i;
				}
				break;
			}
		}
		cout << index << endl;
	}  
    return 0;
}
