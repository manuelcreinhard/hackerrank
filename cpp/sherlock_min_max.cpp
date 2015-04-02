#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;


int main() 
{
    long n; cin >> n;
    vector<int> w;
    for(int i = 0; i < n; i++)
    {
        int e; cin >> e;
        w.push_back(e);
    }
    int p,q; cin >> p >> q;
    int min_v = INT_MAX;
    int min_ = INT_MAX;
    int temp;
    int d_abs;
    int pos;
    if(n != 1){
		vector<int>::iterator it;
		for(int i = q; i >= p; i--){
			pos = 1;
			cout << "i: " << i << endl;
			for(it=w.begin();it != w.end();it++){
				d_abs = abs((*it) - i);
				if(d_abs>0){			
					cout << "abs: " << d_abs << endl;
					temp = min(d_abs,pos);
					if(temp < min_v){
						cout << "min_value was less" << endl;
						min_v = temp;
						min_ = i;
					} else if (temp == min_v && i < min_){
						cout << "min value was same, i was smaller" << endl;
						min_v = temp;
						min_ = i;
					}
				}
				pos++;
			}
		}
		cout << min_ << endl;
	} else {
		cout << min(abs(w[0] - p),abs(w[0] - q)) << endl;
	}
	
    return 0;
}

