#include<bits/stdc++.h>

using namespace std;

bool isCycle(vector<int> adj[], vector<bool>& isVisited, vector<bool>& rec, int s) {
    rec[s]=true;
    isVisited[s]=true;

    for(int i=0; i<adj[s].size(); i++) {
        int v=adj[s][i];
        if(!isVisited[v] && isCycle(adj,isVisited,rec,v))
            return true;
        if(rec[v])
            return true;
    }
    rec[s]=false;
    return false;
}

int main() {
    int n=4;
    vector<int> adj[n];

    adj[0].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);

    vector<bool> isVisited(n,false);
    vector<bool> rec(n,false);

    int s=0;

    for(int i=0; i<n; i++) {
        if(isVisited[i])
            continue;
        if(isCycle(adj,isVisited,rec,s++)) {
            cout<<"Yes cycle.\n";
            return 0;
        }
    }

    cout<<"No cycle.\n";
    return 0;

}
