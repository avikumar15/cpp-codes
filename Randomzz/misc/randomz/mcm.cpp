/**
 * This code belongs to Avi (106118017)
*/
#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
using namespace std;

void vecInput(vi &vec, int n) {
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
}
 
void solve() {
 
    int n;
    vi vec;
    
    cin>>n;
    vecInput(vec,n);

    int dp[n+5][n+5];

    // initialise the dp matrix with all 0
    for(int i=0; i<n+5; i++) {
        for(int j=0; j<n+5; j++)
            dp[i][j]=0;
    }

    // to multiply a matrix with nothing, the cost will be 0.
    for(int i=0; i<n-1; i++) {
        dp[i][i]=0;
    }

    for(int j=2; j<n; j++) {

        for(int i=0; i<n-j; i++) {
            dp[i][i+j-1]=LONG_LONG_MAX;

            for(int k=i; k<i-1+j; k++) {
                dp[i][i+j-1]=min(dp[i][i+j-1],(dp[i][k]+dp[k+1][i+j-1]+vec[i]*vec[k+1]*vec[i+j]));
            }
        }
    }

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-1; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<dp[0][n-2]<<endl;

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
