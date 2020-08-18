#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin>>str;
    int n=str.size();
    
    int low=-1;
    vector<int> last(70,-1);
    int ans=0;
    
    // geeksforgeeks
    
    for(int i=0; i<n; i++) {
        low=max(low,last[str[i]-'a']);
        last[str[i]-'a']=i;
        //cout<<i<<" "<<low<<endl;
        ans=max(ans,i-low);
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
