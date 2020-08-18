#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void solve() {
    int n;
    cin>>n;
    int x[3];
    cin>>x[0]>>x[1]>>x[2];
    
    vector<int> ans(n+5,0);
    
    ans[x[0]]=1;
    ans[x[1]]=1;
    ans[x[2]]=1;

    /**
     * Or else make only ans[0] as 1 and then print ans[n]-1.
    */
    
    for(int i=1; i<=n; i++) {
        for(int j=0; j<3; j++) {
            if(i-x[j]>=0 && ans[i-x[j]]!=0)
                ans[i]=max(ans[i],1+ans[i-x[j]]);
        }
    }
    
    cout<<ans[n]<<"\n";
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
