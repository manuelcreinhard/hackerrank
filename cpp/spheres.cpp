#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double distance(double  s[2][3]){
	double distance = 0;
	for(int i = 0; i < 3; i++){
		distance += pow(s[0][i] - s[1][i],2);
	}
	distance = sqrt(distance);
	return distance;
}

int main() {
	int cases; cin >> cases;
	unsigned int r[2];
	double s[2][3];
	double a[2][3];
	double p[2][3];
	bool intersect;
	double prev_dist,dist;
	while(cases--){
		cin >> r[0] >> r[1];
		cin >> s[0][0] >> s[0][1] >> s[0][2];
		cin >> s[1][0] >> s[1][1] >> s[1][2];
		cin >> a[0][0] >> a[0][1] >> a[0][2];
		cin >> a[1][0] >> a[1][1] >> a[1][2];
		dist = distance(s);
		prev_dist = dist;
		double prev_change_rate = 0;
		double change_rate = 0;
		double t = 1;
		intersect = true;
		//Let's do a Riemann sum like approach
		while(true){
			t++;
			prev_dist = dist;
			char ch;
			for(int i= 0; i < 2; i++){
				cout << i << ": ";
				for(int j = 0; j < 3; j++){
					p[i][j] = a[i][j]*t*t*.5 + s[i][j];
					ch = 'x' + j;
					cout << ch << " " << p[i][j] << " ";
				}
				cout << endl;
			}
			dist = distance(p);
			
			prev_change_rate = change_rate;
			change_rate = prev_dist - dist;
			//cout << "Distance: " << dist << endl;
			//cout << "R1 + R2: " << r[0] + r[1] << endl;
			
			if(dist <= (r[0] + r[1])){
				break;
			}
			if(dist > (2000)){
				intersect = false;
				break;
			}
		}
		if(intersect){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
