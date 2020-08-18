#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int m;

    cin>>n>>m;

    int dp[n+5][m+5];

    string s1,s2;
    cin>>s1>>s2;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dp[i][j]=0;
        }
    }

    int mx=0;

    for(int i=0; i<n; i++) {
        if(s1[i]==s2[0]) {
            dp[i][0]=1;
            mx=1;
        }
    }

    for(int i=0; i<m; i++) {
        if(s2[i]==s1[0]) {
            dp[0][i]=1;
            mx=1;
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(s1[i]==s2[j]) {
                dp[i][j]=dp[i-1][j-1]+1;
                mx=max(mx,dp[i][j]);
            }
        }
    }

    cout<<mx<<endl;

}

int main() {
    int t;
    cin>>t;

    while(t--)
        solve();
    
    return 0;
}
