#include<bits/stdc++.h>

using namespace std;

int knapSack(vector<int> time, int size, int wt, vector<vector<int>>& dp) {
    if(wt==0)
        return 0;
    if(size==0)
        return dp[size][wt]=time[0]*wt;

    if(dp[size][wt]!=-1)
        return dp[size][wt];
    return dp[size][wt]=min(knapSack(time,size-1,wt,dp),time[size-1]+knapSack(time,size,wt-1,dp));
}

void solve() {
    int n,k;
    // trip and cabs
    cin>>n>>k;

    vector<int> vec(k,0);

    for(int i=0; i<k; i++) {
        cin>>vec[i];
    }

    vector<vector<int>> dp(k+5,vector<int>(n+5,-1));

    sort(vec.begin(),vec.end());
    int ans=knapSack(vec,k,n,dp);
    cout<<ans<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
}
