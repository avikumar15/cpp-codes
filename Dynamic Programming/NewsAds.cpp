#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    int m;
    cin>>n>>m;
    vector<pair<int,int>> times;

    for(int i=0; i<n; i++) {
        int t1,t2;
        cin>>t1>>t2;

        times.push_back({t1,t2});
    }

    vector<int> eff(n);

    for(int i=0; i<n; i++)
        cin>>eff[i];

    int ans;

    int dp[n];
    dp[0]=eff[0];

    for(int i=1; i<n; i++) {
        dp[i]=max(dp[i-1],eff[i]);
        for(int j=0; j<i; j++) {
            if(times[i].first>times[j].second+4) {
                dp[i]=max(dp[i],dp[j]+eff[i]);
            }
        }
    }
    
    cout<<dp[n-1]<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
        solve();

}
