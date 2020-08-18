#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int x=-1,y=-1,w=-1;
};

void solve() {
    int v,e;
    cin>>v>>e;
    
    Edge E[e+5];
    int V[v+5];
    int minDist[v+5];
    
    for(int i=0; i<e; i++) {
        int u,v,wt;
        cin>>u>>v>>wt;
        E[i].x=u;
        E[i].y=v;
        E[i].w=wt;
    }
    
    for(int i=1; i<v; i++)
        V[i]=INT_MAX/2-20;
    V[0]=0;
    
    for(int j=0; j<v; j++) {
        for(int i=0; i<e; i++) {
            minDist[E[i].y]=min(minDist[E[i].y],E[i].w+minDist[E[i].x]);
        }
    }
    int fu=0;
    for(int i=0; i<e; i++) {
        if((minDist[E[i].y]>E[i].w+minDist[E[i].x])) {
            fu=1;
            break;
        }
    }
    cout<<fu<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--) 
        solve();
	return 0;
}
