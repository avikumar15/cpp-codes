#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int G[n+5][m+5];
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>G[i][j];
        
        int mx=0;
        int ans=0;
        for(int i=0; i<m; i++) {
            if(G[0][i]==1) {
                mx=i;
                break;
            }
        }
        
        for(int i=1; i<n; i++) {
            if(G[i][mx]==0)
                continue;
            else {
                // ans=i;
                int st=mx;
                for(int j=mx; j>=0; j--) {
                    if(G[i][j]==0) {
                        mx=j+1;
                        break;
                    }
                    if(j<st) 
                        ans=i;
                }
            } 
                
        }
        
        cout<<ans<<endl;
        
    }
	return 0;
}
