#include<bits/stdc++.h>
#define V 5
using namespace std;

class Edge {
    private:
    int p1;
    int p2;
    int weight;

    public:
    Edge() {

    }
    Edge(int pa, int pb, int wt) {
        p1=pa;
        p2=pb;
        weight=wt;
    }

    int getP1() {
        return p1;
    }

    int getWeight() {
        return weight;
    }

    int getP2() {
        return p2;
    }

    void setWeight(int w) {
        weight = w;
    }
};

bool allTrue(vector<bool> visits) {
    for(int i=0; i<visits.size(); i++) {
        if(!visits[i])
            return false;
    }
    return true;
}

bool isCycle(int u, bool visited[], int parent, int graph[V][V]) {
   visited[u] = true;
   for(int v = 0; v<V; v++) {
      if(graph[u][v]) {
         if(!visited[v]) {
            if(isCycle(v, visited, u, graph)) {
               return true;
            }
         } else if(v != parent) {
            return true;    
         }
      }
   }
   return false;
}

Edge findThePos(vector<int> &edgeConsiderable, vector<Edge> edges, int tree[V][V]) {
    
    bool isMark[V];
    for(int i=0; i<V; i++) {
        isMark[i]=false;
    }

    int min=INT_MAX;
    int pos=0;
    Edge e;

    for(int i=0; i<edgeConsiderable.size(); i++) {
    //    int temp = tree[edges[edgeConsiderable[i]].getP1()][edges[edgeConsiderable[i]].getP2()];
    //    tree[edges[edgeConsiderable[i]].getP1()][edges[edgeConsiderable[i]].getP2()]=1;
    //    tree[edges[edgeConsiderable[i]].getP2()][edges[edgeConsiderable[i]].getP1()]=1;
        int temp;
        temp = tree[edges[edgeConsiderable[i]].getP1()][edges[edgeConsiderable[i]].getP2()];
        tree[edges[edgeConsiderable[i]].getP1()][edges[edgeConsiderable[i]].getP2()]=1;
        tree[edges[edgeConsiderable[i]].getP2()][edges[edgeConsiderable[i]].getP1()]=1;
    //    cout<<"Now edge considered - "<<edges[edgeConsiderable[i]].getP1()<<" "<<edges[edgeConsiderable[i]].getWeight()<<" "<<edges[edgeConsiderable[i]].getP2()<<" "<<edgeConsiderable[i]<<endl;
        
        cout<<"tree that is being sent is \n";
        for(int j=0; j<V; j++) {
            for(int k=0; k<V; k++) {
                cout<<tree[j][k]<<" ";
            }
            cout<<endl;
        }

        if(edges[edgeConsiderable[i]].getWeight()<min){//} && !isCycle(0,isMark,-1,tree)) {
            min=edges[edgeConsiderable[i]].getWeight();
            e=edges[edgeConsiderable[i]];
            pos=i;
        }

        tree[edges[edgeConsiderable[i]].getP1()][edges[edgeConsiderable[i]].getP2()]=temp;
        tree[edges[edgeConsiderable[i]].getP2()][edges[edgeConsiderable[i]].getP1()]=temp;
    }
    cout<<"Now edge considered - "<<edges[edgeConsiderable[pos]].getP1()<<" "<<edges[edgeConsiderable[pos]].getWeight()<<" "<<edges[edgeConsiderable[pos]].getP2()<<" "<<edgeConsiderable[pos]<<endl;

        tree[edges[edgeConsiderable[pos]].getP1()][edges[edgeConsiderable[pos]].getP2()]=e.getWeight();
        tree[edges[edgeConsiderable[pos]].getP2()][edges[edgeConsiderable[pos]].getP1()]=e.getWeight();
    
    
    edgeConsiderable.erase(edgeConsiderable.begin()+pos);

    return e;
}

void putDataToEdges(vector<int> &edgeToConsider, int v, vector<bool> &EdgeConsidered, vector<Edge> edges) {
    for(int i=0; i<edges.size(); i++) {
        if((edges[i].getP1() == v || edges[i].getP2() == v) && !EdgeConsidered[i] ) {
            edgeToConsider.push_back(i);
            cout<<"Inserted "<<edges[i].getP1()<<" "<<edges[i].getWeight()<<" "<<edges[i].getP2()<<"\n";
            EdgeConsidered[i]=true;
        }
    }
}

int main() {
    
    cout<<"Number of vertices: ";
    cout<<V<<endl;

    int GRAPH[V][V];
    int GRAPHCopy[V][V];
    vector<Edge> edges;

    cout<<"Enter Graph: \n";
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin>>GRAPH[i][j];
            GRAPHCopy[i][j] = GRAPH[i][j];
            if(GRAPH[i][j]!=0 && i<=j) {
                edges.push_back(Edge(i,j,GRAPH[i][j]));
        //        cout<<edges[edges.size()-1].getP1()<<" "<<edges[edges.size()-1].getP2()<<" "<<edges[edges.size()-1].getWeight()<<"\n";
            }
        }
    }

    cout<<"edges told\n";

    // tree is represented same way like how a graph is represented but without closed paths, parallel edges and self loops.
    int TREE[V][V];
    // initialising tree as all 0s
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            TREE[i][j]=0;
        }
    }

    vector<bool> isVisited(V,false);
    vector<bool> EdgeConsidered(edges.size(),false);
    int pos=0;

    isVisited[0]=true;
    vector<int> edgesToConsider;

    putDataToEdges(edgesToConsider,pos,EdgeConsidered, edges);

    Edge e;

    while(!allTrue(isVisited)) {
        
        e = findThePos(edgesToConsider, edges, TREE);
        cout<<"Position is "<<e.getP1()<<" "<<e.getWeight()<<" "<<e.getP2()<<endl;

        pos = isVisited[e.getP1()] ? e.getP2():e.getP1();
        cout<<"Actual Position is "<<pos<<endl;
        isVisited[pos]=true;

        putDataToEdges(edgesToConsider,pos,EdgeConsidered,edges);

    }

    cout<<"******************************************\nFINALLY THE MST IS\n\n";

    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++)
        cout<<TREE[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}