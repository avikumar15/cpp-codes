#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int t;
    vector<int> vec;
    
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
    int N=n;
    
    int mxl[N+5],mxr[N+5];
    mxl[0]=vec[0];
    mxr[n-1]=vec[n-1];
    
    for(int i=1; i<n; i++)
        mxl[i]=max(mxl[i-1],vec[i]);
        
    for(int i=n-2; i>=0; i--)
        mxr[i]=max(mxr[i+1],vec[i]);
        
    int ans=0;
    for(int i=0; i<n; i++) {
        ans+=min(mxr[i],mxl[i])-vec[i];
    }
    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
    
	return 0;
}
