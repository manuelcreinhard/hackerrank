#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int n,t; cin >> n >> t;
	int * arr = (int *)malloc(sizeof(int)*n);
	int i = 0;
	while(i<n){
		cin >> arr[i];
		i++;
	}
	int entry,exit;
	int width;
	while(t--){
		width = 3;
		cin >> entry >> exit;
		while(entry <= exit){
			if(width > arr[entry]){
				width = arr[entry];
				if(width == 1){
					break;
				}
			}
			entry++;
		}
		cout << width << endl;
	}
    return 0;
}
