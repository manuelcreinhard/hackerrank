#include <unordered_map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

int pairs(unordered_map<long,bool> & a,int k) {
	int ans = 0;
    unordered_map<long,bool>::iterator it;
    it = a.begin();
    long diff;
    while(it != a.end()){
		if(it->first == 0 || it->first == k){
			++it;
			continue;
		}
			diff = it->first - k;		
		if(a.find(diff) != a.end()){
			ans++;	
		}
			++it;
	}
    return ans;
}

/* Tail starts here */
int main() {
    int res;
    
    long _a_size,_k;
    cin >> _a_size>>_k;
    //cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    unordered_map<long,bool> _a = unordered_map<long,bool>();
    _a.clear();
    long _a_item;
    for(long _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        _a[_a_item] = true;
    }
    /*
    unordered_map<long,bool>::iterator it;
    for(it = _a.begin(); it != _a.end(); ++it){
		cout << it->first << " ";
	}
	*/
    res = pairs(_a,_k);
    cout << res;
    
    return 0;
}

