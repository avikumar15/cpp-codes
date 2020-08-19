/* 
Description:
Implements a greedy algorithm for approximate graph coloring problem.
This approximate algorithm guarantees use of no more than MaxDegree+1 colors for coloring the graph.
*/

#include <bits/stdc++.h>
#define V 15

using namespace std; 

void greedyColoring(int g[V][V]) {

    // adj[i] will contain edges that are connected to ith vertex in the graph.
    // size[i] will be size of adj[i].

    int adj[V][V];
    int size[V];

    for(int i=0; i<V; i++) {
        size[i]=0;
    }

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            if(g[i][j]==1) {
                adj[i][size[i]++]=j;
            }
        }
    }

    // result[i] contains the color number to be assigned to ith vertex.

	int result[V]; 

	for (int i = 0; i < V; i++) {
        if(i==0) {
            result[i]=0;
            continue;
        }
		result[i] = -1;
    } 

	bool available[V]; 

	for (int a = 0; a < V; a++) 
		available[a] = false; 

	for (int p = 1; p < V; p++) {

		for (int i = 0; i < size[p]; i++) 
			if (result[adj[p][i]] != -1) {
    //            cout<<"YES\n";
    //            cout<<p<<" "<<i<<" "<<adj[p][i]<<" "<<result[adj[p][i]]<<endl;
				available[result[adj[p][i]]] = true; 
            }

		int a; 
		for (a = 0; a < V; a++) 
			if (available[a] == false) 
				break; 

		result[p] = a; 

    	for (int i = 0; i < size[p]; i++) 
			if (result[adj[p][i]] != -1) 
				available[result[adj[p][i]]] = false; 

	} 

    cout<<"\n*************************\nVERTEX\tColor\n";

	for (int i = 0; i < V; i++) 
		cout<<i<<"\t"<<result[i]<<endl; 
} 

// randomly generate undirected graph.
void putRandomGraph(int graph[V][V]) {

	for(int i=0; i<V; i++) {
		for(int j=i+1; j<V; j++) {
            int rnd = rand()%2;
			graph[i][j]=rnd;
            graph[j][i]=rnd;
        }
	}
}

// Driver program to test above function 
int main() 
{ 
    // default graph.
	int graph[V][V] = {}; 
	
	int mst[V][V] = {};
	int mode=2;

    // number of cities salesman has to visit.
    cout<<"Given number of vertices: "<<V;

	cout<<"\nInput 1 to enter graph or 2 to randomly generate it: ";
	cin>>mode;

	if(mode==1) {		
		cout<<"\nEnter undirected-graph: "<<endl;

		// graph giving a relationship between cities and distances.
		for(int i=0; i<V; i++) 
			for(int j=0; j<V; j++) 
				cin>>graph[i][j];
	
	} else {
		putRandomGraph(graph);
		cout<<"\nGraph is:\n";
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) 
				cout<<graph[i][j]<<" ";
			cout<<endl;
		}
	}

    greedyColoring(graph);

	return 0; 
} 
