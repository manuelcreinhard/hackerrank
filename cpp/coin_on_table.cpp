#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

//global variables
int n,m,k;
pair<int,int> as;

void search(int i, int j, int t, int d, vector<vector<int> > &sPath,vector<vector<char> > &table){
	if(i<0 || i >= n || j < 0 || j>= m || t > k || (i+j) > t){
		return;
	}
	if (sPath[i][j] > d){
		sPath[i][j] = d;
	} 
	search(i+1,j,t+1,d+(table[i][j] != 'D'),sPath,table);
	search(i-1,j,t+1,d+(table[i][j] != 'U'),sPath,table);
	search(i,j+1,t+1,d+(table[i][j] != 'R'),sPath,table);
	search(i,j-1,t+1,d+(table[i][j] != 'L'),sPath,table);
}

int main() {
    scanf("%d %d %d",&n,&m,&k);
    vector<vector<char> > table (n, vector<char> (m));
    for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c",&table[i][j]);
			if(table[i][j] == '*'){
				as = make_pair(i,j);
			}
		}
	}
    //if shortest route can't make it print -1 and exit
	if(as.first+as.second > k){
		printf("-1");
		return 0;
	}
	vector<vector<int> > sPath (n, vector<int> (m,INT_MAX));
	search(0,0,0,0,sPath,table);
	printf("%d\n",sPath[as.first][as.second]);
	return 0;
}
