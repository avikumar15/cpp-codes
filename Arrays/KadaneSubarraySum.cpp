#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int t;
    vector<int> vec;
    
    for(int i=0; i<n; i++) 
        cin>>t, vec.push_back(t);
        
    int ans=INT_MIN+50;
    int sum=0;
    // 1 -2 3 -2 5
    for(int i=0; i<n; i++) {
        sum+=vec[i];
        ans=max(ans,sum);
        sum=max(sum,0);
    }
    
    cout<<ans<<endl;
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
