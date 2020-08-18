#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> vec(n);
    int sum=0;
    
    for(int i=0; i<n; i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    
    // if(sum%2==1) {
    //     cout<<"NO\n";
    //     return;
    // }
    
    // sum/=2;
    cin>>sum;
    // 1 5 11 5
    
    int dp[sum+1][n+1];
    
    for(int i=0; i<n+1; i++)
        dp[(int)0][i]=(int)1;
        
    for(int i=1; i<sum+1; i++)
        dp[i][(int)0]=(int)0;
        
    for(int i=1; i<sum+1; i++) {
        for(int j=1; j<n+1; j++) {
            if(vec[j-1]>i) {
                dp[i][j]=dp[i][j-(int)1];
            } else {
                dp[i][j]=dp[i][j-(int)1]+dp[i-vec[j-(int)1]][j-(int)1];
            }
        }
    }

    for(int i=0; i<sum+1; i++) {
        for(int j=0; j<n+1; j++) 
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    
    if(dp[sum][n]>(int)0)
        cout<<"YES\n";
    else 
        cout<<"NO\n";
    
}

int32_t main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        solve();
    }
    
	return 0;
}
