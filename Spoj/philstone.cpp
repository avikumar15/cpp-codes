#include<bits/stdc++.h>
#define int long long int
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;

map<int,int> mmap;

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void solve() {

    int m,n;

    cin>>m>>n;

    int temp;
    int graph[m+5][n+5];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin>>graph[i][j];
        }
    }

    int dp[m+5][n+5];

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(i==0) {
                dp[i][j]=graph[i][j];
            } else {
                if(j!=0 && j!=n-1)
                    dp[i][j]=graph[i][j]+max( {dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1] } );
                else if(j==0)
                    dp[i][j]=graph[i][j]+max( {dp[i-1][j], dp[i-1][j+1] } );
                else 
                    dp[i][j]=graph[i][j]+max( {dp[i-1][j], dp[i-1][j-1] } );
            }
        }
    }

    int maxx=LONG_LONG_MIN;

    // cout<<endl;
    // for(int i=0; i<m; i++) {
    //     for(int j=0; j<n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    for(int i=0; i<n; i++){
        maxx=max(maxx,dp[m-1][i]);
    }
    
    cout<<maxx<<endl;


}
 
int32_t main() {
    
    fastio;

    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }

    return 0;
}
