#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int>& res, vector<int> adj[], vector<bool>& isVisited, int s) {
    
    isVisited[s]=true;
    res.push_back(s);

    for(int i=0; i<adj[s].size(); i++) {
        if(!isVisited[adj[s][i]])
        dfs(res,adj,isVisited,adj[s][i]);
    }
}

void solve() {
    int n;
    int e;
    cin>>n>>e;
    vector<int> adj[n+5];
    for(int i=0; i<e; i++) {
        int t1,t2;
        cin>>t1>>t2;
        adj[t1].push_back(t2);
    }
    vector<int> res;
    int u,v;
    cin>>u>>v;
    vector<bool> isVisited(n+5,false);
    dfs(res,adj,isVisited,u);
    int ans=-1;
    for(int i=0; i<res.size(); i++) {
        if(res[i]==v) {
            ans=1;
            break;
        }
    }

    if(ans==-1)
        cout<<"Can't\n";
    else 
        cout<<"Can\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}
