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

    int n;
    cin>>n;
    int temp;

    vi vec;
    vector<vector<int>> vecs;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    int dp[n+15];

    dp[0]=1;
    if(vec.size()>1)
    if(vec[0]<vec[1]) {
        dp[1]=2;
    } else {
        dp[1]=1;
    }

    for(int i=3; i<=n; i++) {
        vi fact;
        int v=1;
        for(int f=1; f*f<=i; f++) {
            // cout<<f<<" ";
            if(i%f==0) {
                if(vec[i-1]>vec[f-1])
                v=max(v,1+dp[f-1]);
                if(f!=1)
                if(vec[i-1]>vec[i/f-1])
                v=max(v,1+dp[i/f-1]);
            }
        }
        dp[i-1]=v;
        // cout<<endl;
    }
    int mx=LONG_LONG_MIN;
    for(int i=0; i<n; i++) {
        mx=max(mx,dp[i]);
        // cout<<dp[i]<<" ";
    }

    cout<<mx<<endl;


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
