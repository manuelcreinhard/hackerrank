#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	unsigned long l; 
	unsigned long arr[100];
	for(l = 0; l < 100; l++){
		arr[l] = 0;
	}
	cin >> l;
	int t;
	string nouse;
	while(l--){
		cin >> t >> nouse;
		arr[t]++;
	}
	int total = 0;
	for(l = 0; l < 100; l++){
		total += arr[l];
		cout << total << " ";
	}
	cout << endl;
    return 0;
}
