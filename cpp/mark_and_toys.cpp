#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long long n, k; cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int p; cin >> p;
        prices.push_back(p);
    }
    
    sort(prices.begin(),prices.end());
    int count = 0;
    int temp;
    vector<int>::iterator it;
    for(it = prices.begin(); it != prices.end() && k > 0; it++){
		temp = *it;
		if(k - temp > 0){
			count++;
			k-=temp;
		}
	}
    
    // Write the code for computing the final answer using n,k,prices
    
    cout << count << endl;
    
    return 0;
}

