#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int walk(vector<vector<char> > & map_, int * prev, int * pos, int n, int m){
	//cout << "Walk..." << endl;
	int xy[2];
	int paths = 0;
	int v;
	int save = 0;
	int dir[2][4] = 
	{
		{1,0,-1,0},
		{0,1,0,-1}
	};
	for(int i = 0; i < 4; i++){
		xy[0] = pos[0] + dir[0][i];
		xy[1] = pos[1] + dir[1][i];
		//Avoid getting outside
		if(xy[0] < 0 || xy[0] >= n || xy[1] < 0 || xy[1] >= m){
			paths--;
			continue;
		}
		//Avoiding infinite loops
		if(xy[0] == prev[0] && xy[1] == prev[1]){
			paths--;
			continue;
		}
		if(map_[xy[0]][xy[1]] == 'X'){
			paths--;
			continue;
		}
		if(map_[xy[0]][xy[1]] == '*'){
			cout << "Found the exit..." << endl;
			return 0;
		}
		v = walk(map_,pos,xy,n,m);
		if(v > -1){
			save = v;
			cout << "Pre-save: " << save << endl;
		}
	}
	if(paths==-4){
		return -1;
	} else if (paths == -3) {
		cout << "x: " << pos[0] << " y: " << pos[1] << endl;
		cout << "Paths: " << paths << endl;
		cout << "Save: " << save << endl;
		return save;
	}
	cout << "x: " << pos[0] << " y: " << pos[1] << endl;
	cout << "Paths: " << (paths + 4) << endl;
	cout << "Save: " << save << endl;
	return save + 1;
}

int main() {
	int cases; cin >> cases;
	int n,m,k;
	int hermionie[2];
	char c;
	while(cases--){
		cout << "iteration: " << cases << endl << endl;  
		cin >> n >> m;
		vector<vector<char> > map_;
		for(int i = 0; i < n; i++){
			vector<char> line_;
			for(int j = 0; j < m; j++){
				cin >> c;
				line_.push_back(c);
				if(c == 'M'){
					hermionie[0] = i;
					hermionie[1] = j;
				}
			}
			map_.push_back(line_);
		}
		cin >> k;
		cout << "Printing map..." << endl << endl;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << map_[i][j];
			}
			cout << endl;
		}
		int v = walk(map_, hermionie, hermionie, n,m);
		cout << "v: " << v << endl;
	}
    return 0;
}
