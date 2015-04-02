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
    
    sort(w.begin(),w.end());
    int last = INT_MAX;
    int count = 0;
    vector<int>::iterator it;
    for(it = w.begin(); it != w.end(); it++){
		if(*it <= last + 4){
			continue;
		} else {
			last = *it;
			count++;
		}
	}
    cout << count << endl;
    return 0;
}
