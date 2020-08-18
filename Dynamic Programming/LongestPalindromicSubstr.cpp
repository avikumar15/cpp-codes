#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin>>str;
    
    int n=str.size();
    int dp[n][n];
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            dp[i][j]=0;
    
    for(int i=0; i<n; i++)
        dp[i][i]=1;
        
    for(int i=0; i<n-1; i++)
        if(str[i]==str[i+1])
            dp[i][i+1]=1;
        
    for(int i=2; i<n; i++) {
        int c=i;
        for(int j=0; j<n-c; j++) {
            if(str[j]==str[i])
                dp[j][i]=dp[j+1][i-1];
        
            i++;
        }
        i=c;
    }
    
    int ml=1;
    int mx=0;
    int my=0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dp[i][j]==1 && j-i+1>ml) {
                mx=i;
                my=j;
                ml=j-i+1;
            }
        }
    }
    
    cout<<str.substr(mx,ml)<<endl;
    
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
