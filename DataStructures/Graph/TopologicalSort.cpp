#include<bits/stdc++.h>

using namespace std;

void topo(vector<int> adj[], vector<bool>& isVisited, int s, stack<int>& st) {
    if(isVisited[s])
        return;
    
    isVisited[s]=true;

    for(int i=0; i<adj[s].size(); i++) {
        topo(adj,isVisited,adj[s][i],st);
    }

    st.push(s);
}

int main() {
    int n=4;
    vector<int> adj[n];

    adj[0].push_back(1);
    adj[1].push_back(3);
    adj[2].push_back(1);
    adj[2].push_back(3);

    int s=0;
    
    vector<bool> isVisited(n,false);
    stack<int> st;

    for(int i=0; i<n; i++) {
        if(isVisited[i]) {
            s++;
            continue;
        }
        
        topo(adj,isVisited,s++,st);

    }

    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }

}
