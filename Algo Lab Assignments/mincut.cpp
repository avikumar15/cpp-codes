#include <bits/stdc++.h>
#define vvi vector<vector<int>>
#define vi vector<int>

using namespace std; 

void dfs(vvi graphr, int s, bool isVisited[]) {

    int V=graphr.size();
	isVisited[s] = true; 
	for (int i = 0; i < V; i++) 
	if (graphr[s][i] && !isVisited[i]) 
		dfs(graphr, i, isVisited); 
} 

int bfs(vvi graphr, int root[], int s, int t) {

	int V=graphr.size();
	bool isVisited[V]; 

    for(int i=0; i<V; i++)
        isVisited[i]=false;

	queue <int> q; 
	q.push(s); 
	isVisited[s] = true; 
	root[s] = -1; 

	while (!q.empty()) {

		int u = q.front(); 
		q.pop(); 

		for (int i=0; i<V; i++) {

			if (isVisited[i]==false && graphr[u][i] > 0) { 
				q.push(i); 
				root[i] = u; 
				isVisited[i] = true; 
			} 
		} 
	} 

	return (isVisited[t]); 
} 

// prints minimum cuts required to make graph disconnected.
void minCut(vvi graph, int s, int t) {

	int u, v; 

	int V=graph.size();
	vvi graphr(V,vi(V));
	int root[V];
	
    // making graphr equal to graph (copy of graph).
    for (u = 0; u < V; u++) 
		for (v = 0; v < V; v++) 
			graphr[u][v] = graph[u][v]; 


    for(int i=0; i<V; i++) {
        root[i]=0;
    }

    // Increase flow if a path exist between source and sink
	while (bfs(graphr, root, s, t)) {

		int minn = INT_MAX; 

		for (v=t; v!=s; v=root[v]) { 
			u = root[v]; 
            if(graphr[u][v]<minn)
                minn=graphr[u][v];
		} 

		for (v=t; v != s; v=root[v]) { 
			u = root[v]; 
			graphr[u][v] -= minn; 
			graphr[v][u] += minn; 
		} 
	} 

    // to check v that can be visited from s.
	bool isVisited[V]; 

    for(int i=0; i<V; i++) {
        isVisited[i]=false;
    }

	dfs(graphr, s, isVisited); 
 
    cout<<"Following are minimum cuts along with flow to make the graph disconnected:"<<endl;
	for (int i = 0; i < V; i++) 
	    for (int j = 0; j < V; j++) 
		    if ( graph[i][j] && isVisited[i] && !isVisited[j] ) 
			    cout<<i<<" -- "<<graph[i][j]<<" -- "<<j<<endl; 

	return; 
} 

void solve() {
    
    int V,E;
	int s,t,f;

    // graph input.
    cout<<"Input the number of vertices and number of edges of the graph: ";
	cin>>V>>E;
	
    vvi GRAPH(V,vi(V));
    
    // initialise graph as all 0.
    for(int i=0;i<V;i++)
	    for(int j=0;j<V;j++)
	        GRAPH[i][j]=0;

    // input edge details.
	for(int i=1;i<=E;i++){
	    cout<<"Enter first Vertex ,flow and second Vertex of edge "<<i<<" : ";
	    cin>>s>>f>>t;
	    GRAPH[s][t]=f;
	}

	int src,sink;
	cout<<"\nEnter source vertex and sink vertex: ";
	cin>>src>>sink;
	
    minCut(GRAPH, src, sink); 

}

int main() { 

    int t=1;
    cout<<"Enter number of TestCases: ";
    cin>>t;

    while(t--) {
        solve();
    }

    return 0; 
} 
