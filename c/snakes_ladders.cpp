#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

const int INF = 2000000000;
typedef pair<int,int> PII;

#define V 101
#define min(x, y) (x<y?x:y)
#define max(x, y) (x>y?x:y)

int main(){
	int T, L, S;
	scanf("%d", &T);
	
	for(int t = 0; t<T; t++){
		vector<vector<PII> > edges(V);
		scanf("%d,%d", &L, &S);
		PII edge;
		for(int l = 0; l<L; l++){
			scanf("%d,%d", &edge.first, &edge.second);
			edges[edge.first].push_back (make_pair (0, edge.second));
		}
		for(int s = 0; s<S; s++){
			scanf("%d,%d", &edge.first, &edge.second);
			edges[edge.first].push_back (make_pair (0, edge.second));
		}
		for(int v = 1; v<V; v++){
			for(int i = 1; i<=6; i++){
				if(i+v>=V) break;
				else{
					edges[v].push_back(make_pair(1, v+i));
				}
			}
		}



		priority_queue<PII, vector<PII>, greater<PII> > Q;
		vector<int> distTo(V, INF), edgeTo(V, -1);
		// Source Vertex Entry
		Q.push(make_pair (0, 1));
		distTo[1] = 0;
		while(!Q.empty()){
			PII p = Q.top();
			// Sink Vertex Check
			if (p.second == 100) break;
			Q.pop();
			int here = p.second;
			for (vector<PII>::iterator it=edges[here].begin(); 
					it!=edges[here].end(); it++){
				if (distTo[here] + it->first < distTo[it->second]){
					distTo[it->second] = distTo[here] + it->first;
					edgeTo[it->second] = here;
					Q.push (make_pair (distTo[it->second], it->second));
				}
			}
		}
		printf("%d\n", distTo[100]);
	}

	return 0;
}
