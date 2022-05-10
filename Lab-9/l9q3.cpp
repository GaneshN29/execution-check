#include <bits/stdc++.h>
#define V 6

using namespace std;

void tsp(int graph[][V], vector<bool>& v, int currPos, int n, int count, int cost, int& ans){
    if(count==n && graph[currPos][0]){
		ans = min(ans, cost+graph[currPos][0]);
		return;
	}
    for(int i = 0; i<n; i++) if(!v[i] && graph[currPos][i]){
        v[i] = true;
        tsp(graph, v, i, n, count+1, cost + graph[currPos][i], ans);
        v[i] = false;
	}
    return;
}

int main(){
    cout<<"Program to find the weight for travelling salesman problem.\n";
    cout<<"Enter the number of vertices in the graph: ";
    int n;
    cin>>n;
    int graph[n][V];
    cout<<"Enter the adjacency matrix:"<<endl;
    for(int i = 0; i<n; i++) for(int j = 0; j<n; j++) cin>>graph[i][j];
    vector<bool> v(n);
    for(int i = 0; i<n; i++) v[i] = false;
    v[0] = true;
	int ans = INT_MAX;
    tsp(graph, v, 0, n, 1, 0, ans);
    cout<<ans;
	return 1;
}
