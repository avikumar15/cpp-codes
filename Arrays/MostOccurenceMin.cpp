#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> arr;
    for(int i=0; i<n; i++)
        cin>>t, arr.push_back(t);
    for(int i=0; i<n; i++)
        arr[arr[i]%k]+=k;
    int mx=INT_MIN+50;
    int ans=arr[0];
    
    for(int i=0; i<n; i++) {
        if((arr[i]/k)>(mx/k)) {
            mx=arr[i];
            ans=i;
        }
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
