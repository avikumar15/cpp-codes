#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> G, int r, int c, int key, int col, int row) {
    
    if(r<0 || c>=col || c<0 || r>=row)
        return -1;
    
    if(G[r][c]==key)
        return r*10+c;
        
    if(G[r][c]<key)
        return solve(G,r+1,c,key,col,row);
        
    else 
        return solve(G,r,c-1,key,col,row);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n,m;
        int key;
        cin>>n>>m;
        vector<vector<int>> G;
        int x;
        
        for(int i=0; i<n; i++) {
            vector<int> t;
            for(int j=0; j<m; j++) {
                cin>>x;
                t.push_back(x);
            }
            G.push_back(t);
        }
        cin>>key;
        
        int ans = solve(G,0,m-1,key,m,n);
        if(ans==-1)
            cout<<0<<endl;
        else 
            cout<<1<<endl;
    }
	return 0;
}
