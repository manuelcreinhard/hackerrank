#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int l; 
	int arr[100];
	for(l = 0; l < 100; l++){
		arr[l] = 0;
	}
	cin >> l;
	int t;
	while(l--){
		cin >> t;
		arr[t]++;
	}
	for(l = 0; l < 100; l++){
		cout << arr[l] << " ";
	}
	cout << endl;
    return 0;
}
