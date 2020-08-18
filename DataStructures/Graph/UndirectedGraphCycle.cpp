#include<bits/stdc++.h>

using namespace std;

bool isCycle(vector<int> adj[], vector<bool>& isVisited, int p, int s) {
    
    isVisited[s]=true;

    for(int i=0; i<adj[s].size(); i++) {
        int v=adj[s][i];
        if(isVisited[v] && v!=p)
            return true;
        if(!isVisited[v] && isCycle(adj,isVisited,s,v))
            return true;
    }
    
    return false;
}

int main() {
    int n=4;
    vector<int> adj[n];

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(2);

    vector<bool> isVisited(n,false);

    int s=0;

    for(int i=0; i<n; i++) {
        if(isVisited[i])
            continue;
        if(isCycle(adj,isVisited,-1,s++)) {
            cout<<"Yes cycle.\n";
            return 0;
        }
    }

    cout<<"No cycle.\n";
    return 0;

}
