#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n;
    cin>>n;
    
    int G[n+5][n+5];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>G[i][j];
            
    for(int cnt=0; cnt<n; cnt++) {
        int M[n+5][n+5];
        for(int i=0; i<n; i++)
            M[cnt][i]=G[cnt][i];
        for(int i=0; i<n; i++)
            M[i][cnt]=G[i][cnt];
        for(int i=0; i<n; i++)
            M[i][i]=G[i][i];
        for(int i=0; i<n; i++) {
            if(i==cnt)
                continue;
            for(int j=0; j<n; j++) {
                if(j==cnt)
                    continue;
                if(i==j)
                    continue;
                M[i][j]=min(G[i][j],M[i][cnt]+M[cnt][j]);
            }
        }
        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++)
                G[i][j]=M[i][j];
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(G[i][j]>=pow(10,6))
                cout<<"INF ";
            else 
                cout<<G[i][j]<<" ";
        }
        cout<<endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
        solve();
    
	return 0;
}
