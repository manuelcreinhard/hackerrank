#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    int cases; cin >> cases;
    double sum = 0;
    int temp;
    while(cases--){
        cin >> temp;
        sum += temp;
    }
    sum /=2;
    cout << fixed << setprecision(1) << sum << endl;
    return 0;
}
