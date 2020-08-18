#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int src;
    int dest;
};

int getParent(vector<int>& parent, int p) {
    if(parent[p]==-1)
        return p;
    return getParent(parent,parent[p]);
}

void Union(vector<int>& parent, int x, int y) {
    int xset=getParent(parent,x);
    int yset=getParent(parent,y);

    if(xset!=yset)
        parent[xset]=yset;
}

bool isCycle(vector<Edge> ed, int n, int v) {
    vector<int> parent(v+5,-1);

    for(int i=0; i<n; i++) {

        int x=getParent(parent,ed[i].src);
        int y=getParent(parent,ed[i].dest);

        if(x==y)
            return true;
        
        // cout<<x<<" "<<y<<endl;

        Union(parent,x,y);

    }

    for(int i=0; i<v; i++) {
        cout<<i<<" : ";
        cout<<getParent(parent,i)<<"\n";
    }

    return false;

}

int main() {

    int n=4;
    int v=6;

    vector<Edge> ed(n);

    ed[0].src=0;
    ed[0].dest=1;

    ed[1].src=1;
    ed[1].dest=2;

    ed[2].src=1;
    ed[2].dest=3;

    ed[3].src=4;
    ed[3].dest=5;

    if(isCycle(ed, n, v))
        cout<<"Cycle\n";
    else 
        cout<<"No Cycle\n";

}
