#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(25)
#define PI 4*atan(1)
 
using namespace std;

void solve() {
    int temp;
    vi vec;

    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    int dp[n+5];
    dp[0]=0;
    if(vec.size()>1) {
        dp[1]=((vec[0]<vec[1])?1:0);
        
    }

    for(int i=2; i<n; i++) {
        if(vec[i]>vec[i-1]) {
            dp[i]=dp[i-1]+1;
        } else {

        }
    }

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
