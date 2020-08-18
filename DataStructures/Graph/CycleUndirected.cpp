// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/

bool doesIt(vector<int> adj[], int s, int p, vector<bool>& isV) {
    isV[s]=true;
    for(int i=0; i<adj[s].size(); i++) {
        if(isV[adj[s][i]]) {
            // it contains.
            if(adj[s][i]!=p)
                return true;
        } else {
            if(doesIt(adj,adj[s][i],s,isV))
                return true;
        }
    }
    return false;
} 

bool isCyclic(vector<int> g[], int V) {
    
    vector<bool> isVis(V+5,false);
    bool ans=false;
    
    for(int s=0; s<V; s++) {
        if(isVis[s])
            continue;
        ans=ans||doesIt(g,s,-1,isVis);    
    }
    return ans;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends