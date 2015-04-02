#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() 
{
    int n,k; cin >> n >> k;
    vector<int> w;
    for(int i = 0; i < n; i++)
    {
        int e; cin >> e;
        w.push_back(e);
    }
    
    
    sort(w.begin(),w.end(),std::greater<int>());
    vector<int>::iterator it;
    int total = 0;
    int count = 0;
    for(it = w.begin();it!=w.end();it++){
		total+= (*it)*(1+(count/k));
		count++;
	}
    cout << total << endl;
    return 0;
}

