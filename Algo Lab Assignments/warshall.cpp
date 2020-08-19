#include<bits/stdc++.h>
#define V 4

using namespace std;

int main() {

    cout<<endl<<"Number of Vertices: "<<V<<endl;
    cout<<"Input the graph in matrix format: "<<endl;

    // graph input.
    int GRAPH[V][V];

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin>>GRAPH[i][j];

            // for convenience making all no connection pair of vertices as INFINITY.
            if(GRAPH[i][j]==0 && i!=j) {
                 GRAPH[i][j]=INT_MAX/3;
            }
        }
    }

    // run graph from G^1 to G^V
    for(int t=1; t<=V; t++) {

        cout<<endl<<"----------------------------------"<<endl;
        cout<<"Stage: G"<<t<<endl;
        // to make a copy of GRAPH data at every new iteration.
        int GRAPHcopy[V][V];
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                GRAPHcopy[i][j]=GRAPH[i][j];

        for(int i=0; i<V; i++) {

            if(t-1==i)          continue;

            for(int j=0; j<V; j++) {
                GRAPH[i][j] = min({ GRAPH[i][j], (GRAPHcopy[i][t-1] + GRAPHcopy[t-1][j]) });
            }
        }

        for(int i=0; i<V; i++) {

        for(int j=0; j<V; j++) {
            cout<<GRAPH[i][j]<<" ";
        }
        
        cout<<endl;
    }
    }

    int finalAnswer=0;

    cout<<endl<<"**************************"<<endl;
    cout<<"Minimum distance matrix is: "<<endl<<endl;
    for(int i=0; i<V; i++) {

        for(int j=0; j<V; j++) {
        
            cout<<GRAPH[i][j]<<" ";
            if(j>i) {
                finalAnswer+=GRAPH[i][j];
            }
        }
        
        cout<<endl;
    }

    cout<<endl<<"*******************************"<<endl;
    cout<<"The total distance (sum of all d(u,v)) is "<<finalAnswer<<endl;

    return 0;
}