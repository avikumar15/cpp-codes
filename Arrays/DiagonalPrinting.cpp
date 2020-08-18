#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int G[3*n+5][3*n+5];
    for(int i=0; i<3*n+5; i++)
        for(int j=0; j<3*n+5; j++) 
            G[i][j]=-1;
            
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++) 
            cin>>G[i][j];
        
    int i=0,j=0;
    int s=1;
    int cnt=0;
    
    while(1) {
        if(G[i][j]==-1){
            cnt++;
        }
            
        while(j>=0) {
            if(G[i][j]!=-1)
            cout<<G[i++][j--]<<" ";
            else {
                i++;
                j--;
            }
        }
        cout<<endl;
        i=0;
        j=s++;
        if(cnt>=n)
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
        solve();
    
	return 0;
}
