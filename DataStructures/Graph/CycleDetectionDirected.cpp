// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool doesIt(vector<int> adj[], vector<bool>& visited, int v, vector<bool>& recStack) {
    
    visited[v]=true;
    recStack[v]=true;
        
    for(int i=0; i<adj[v].size(); i++) {
        if(!visited[adj[v][i]])
            if(doesIt(adj,visited,adj[v][i],recStack))
                return true;
        if(recStack[adj[v][i]])
            return true;
    }
    recStack[v]=false;
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    vector<bool> IsV(V+5,false);
    vector<bool> rec(V+5,false);
    bool ans=false;
    for(int s=0; s<V; s++) {
        if(IsV[s])
            continue;
        ans=ans||doesIt(adj,IsV,s,rec);
    }
    return ans;
}

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends