#include<bits/stdc++.h>
#define INF 100000

using namespace std;

struct Edge{
    int dest;
    int dis;
    Edge(int d, int w) {
        dest=d;
        dis=w;
    }
};

void dijikstra(vector<Edge> adj[], int dist[], int n, int src) {

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> vertexPq;

    for(int i=0; i<n; i++) {
        vertexPq.push({dist[i],i});
    }

    while(vertexPq.size()>0) {
        pair<int,int> top=vertexPq.top();
        vertexPq.pop();

        for(int i=0; i<adj[top.second].size(); i++) {
            if(dist[adj[top.second][i].dest]>dist[top.second]+adj[top.second][i].dis) {
                dist[adj[top.second][i].dest]=min(dist[adj[top.second][i].dest],dist[top.second]+adj[top.second][i].dis);
                vertexPq.push({dist[adj[top.second][i].dest],adj[top.second][i].dest});
            }
        }

    }

}

int main() {
    
    int n=5;
    vector<Edge> adj[n];

    adj[0].push_back(Edge(2,5));
    adj[0].push_back(Edge(4,12));
    adj[0].push_back(Edge(1,12));
    
    adj[2].push_back(Edge(4,3));
    adj[2].push_back(Edge(3,1));

    adj[3].push_back(Edge(4,1));
    int src=0;

    int dist[n]={INF,INF,INF,INF,INF};
    dist[src]=0;

    dijikstra(adj,dist,n,src);

    for(int i=0; i<n; i++)
        cout<<dist[i]<<" ";

}
