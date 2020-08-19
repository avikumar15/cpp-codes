#include<bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cout<<"Enter number of test case: ";
    cin>>t;

    while(t--) {
        
            int N,E;
            cout<<"Enter the size of graph: ";
            cin>>N;

            cout<<"Enter number of edges: ";
            cin>>E;

            // To store all type of connection of vertices.
            vector<int> row[N];

            cout<<"Enter vertices with edges:\n";

            int V1,V2;

            for(int i=0; i<E; i++) {
                cin>>V1;
                cin>>V2;

                row[V1].push_back(V2);
                row[V2].push_back(V1);
            }
            
            vector<bool> reached(N,false);

            for(int i=0; i<N; i++) {
                
                if(!reached[i]) {
                    for(int j=0; j<row[i].size(); j++) {

                        if(!reached[row[i][j]]) {

                            reached[i]=true;
                            reached[row[i][j]]=true;
                            break;
                        }
                    }
                }
            }

            for(int i=0; i<N; i++) {

                if(reached[i]) {
                    cout<<i<<" ";
                }
            }
            cout<<endl;
    }

    return 0;
}