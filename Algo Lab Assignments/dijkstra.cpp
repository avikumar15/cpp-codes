#include<bits/stdc++.h>
#define V 4

using namespace std;

// a class defining a vertex.
class VERTEX {
    private:
    int vertexNumber;
    vector<int> distances;

    public:
    VERTEX() {

    }
    
    int getVertexNumber() {
        return vertexNumber;
    }

    vector<int> getDistances() {
        return distances;
    }

    VERTEX(int N, int num);
    void dijkstraAlgorithm(int graph[V][V]);
    bool somePointNotCovered(vector<bool> coveredPoints);
    int findMinimumDistanceVertex(vector<bool> &coveredPoints);
};

// assigning vertex number with N and distance (which is distance from source point) as infinite except for the source vertex.
VERTEX::VERTEX (int N, int num) {
    vertexNumber = N;

    for(int i=0; i<num; i++) {
        distances.push_back(INT_MAX);
    }
    distances[N]=0;
}

// returns vertex with minimum distance and that is not yet taken if nothing found returns -1.
int VERTEX::findMinimumDistanceVertex(vector<bool> &coveredPoints) {
    int min=INT_MAX;
    int pos=-1;

    for(int i=0; i<distances.size(); i++) {
        if(!coveredPoints[i] && distances[i]<min) {
            min=distances[i];
            pos=i;
        }
    }
    if(pos!=-1)
    coveredPoints[pos]=true;
    return pos;
}

// returns true if some point is not yet put in the shortest path tree set.
bool VERTEX::somePointNotCovered(vector<bool> coveredPoints) {
    for(int i=0; i<coveredPoints.size(); i++) {
        if(!coveredPoints[i]) {
            return true;
        }
    }
    return false;
}

// finds min distance of every vertex from the particular vertex.
void VERTEX::dijkstraAlgorithm(int graph[V][V]) {
    vector<bool> coveredPoints(V,false);

    while(somePointNotCovered(coveredPoints)) {
        int minDistanceVertex = findMinimumDistanceVertex(coveredPoints);
        if(minDistanceVertex!=-1) {
            int start=distances[minDistanceVertex];
            for(int i=0; i<V; i++) {
                if(!coveredPoints[i] && (start+graph[minDistanceVertex][i]<distances[i] && graph[minDistanceVertex][i]!=0)) {
                    distances[i] = start+graph[minDistanceVertex][i];
                }
            }
        } else {
            break;
        }
    }
}

int main() {

    cout<<"Number of Vertices: "<<V<<endl;
    cout<<"Input the graph in matrix format: "<<endl;

    // graph input.
    int GRAPH[V][V];
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            cin>>GRAPH[i][j];
        }
    }

    int currentVertex=0;
    
    VERTEX v[V];

    while(currentVertex<V) {
        v[currentVertex] = VERTEX(currentVertex,V);
        v[currentVertex].dijkstraAlgorithm(GRAPH);
        currentVertex++;
    }

    int finalAnswer = 0;

    // Printing minimum distances.
    cout<<endl<<"*******************************"<<endl;
    cout<<"Distances: "<<endl<<endl;

    for(int j=0; j<V; j++) {
        
        cout<<"From Vertex- "<<j+1<<endl;
        for(int i=0; i<V; i++) {

            if(i==j)        continue;

            cout<<"Vertex "<<i+1<<" is at a min. distance of "<<v[j].getDistances()[i]<<endl;
            
            if(i>j) {
                finalAnswer+=v[j].getDistances()[i];
            }
        }
        cout<<"--------------------------------------"<<endl;
    }

    cout<<endl<<"*******************************"<<endl;
    cout<<"The total distance (sum of all d(u,v)) is "<<finalAnswer<<endl;

    return 0;
}