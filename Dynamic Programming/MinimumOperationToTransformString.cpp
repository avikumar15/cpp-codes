#include<bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    string s1,s2;

    cin>>s1>>s2;

    int n=s1.size(),m=s2.size();

    int dp[n+5][m+5];

    for(int i=0; i<n+5; i++) {
        for(int j=0; j<m+5; j++) {
            dp[i][j]=0;
        }
    }

    for(int i=1; i<n; i++) {
        dp[i][0]=i;
    }

    for(int i=1; i<m; i++) {
        dp[0][i]=i;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
            }
        }
    }
    
    cout<<dp[n][m]<<endl;
}

int32_t main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}
