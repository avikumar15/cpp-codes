#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin>>n;
    int t;
    vector<int> vec;
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
    int dp[n+5];
    if(n==0)
        return -1;
    if(n==1)
        return vec[0];
    dp[0]=vec[0];
    dp[1]=max(vec[0],vec[1]);
    
    for(int i=2; i<n; i++) {
        dp[i]=max(dp[i-1],vec[i]+dp[i-2]);
    }
    return dp[n-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
        cout<<solve()<<"\n";
        
	return 0;
}
