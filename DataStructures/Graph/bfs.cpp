// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

void bfs(vector<int>& res, vector<bool>& isV, int s, vector<int> g[]) {
    if(isV[s])
        return;
    isV[s]=true;
    vector<int> temp;
    for(int i=0; i<g[s].size(); i++) {
        if(!isV[g[s][i]]) {
            temp.push_back(g[s][i]);
            res.push_back(g[s][i]);
        }
    }
    for(int i=0; i<temp.size(); i++) 
        bfs(res,isV,temp[i],g);
}

vector <int> bfs2(vector<int> g[], int N) {
    int n=N;
    vector<int> res;
    vector<bool> isV(n+5,false);
    for(int s=0; s<n; s++) {
        if(isV[s])
            continue;
        res.push_back(s);
        bfs(res,isV,s,g);
    }
    return res;
}

//ITERATIVE bfs
vector <int> bfs(vector<int> g[], int N) {
    int n=N;
    vector<int> res;
    vector<bool> isV(n+5,false);
    queue<int> q;
    
    for(int s=0; s<n; s++) {
        if(isV[s])
            continue;
        q.push(s);
        res.push_back(s);
        while(!q.empty()) {
            int f=q.front();
            q.pop();
            for(int i=0; i<g[f].size(); i++) {
                if(!isV[g[f][i]]) {
                    isV[g[f][i]]=true;
                    q.push(g[f][i]);
                    res.push_back(g[f][i]);
                }
            }
        }
    }

    return res;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/

