#include <bits/stdc++.h>
#define int long long
using namespace std;

void merge(vector<int>& vec, int l, int r, int& ans) {
    vector<int> a,b;
    int m=l+(r-l)/2;
    for(int i=l; i<=m; i++)
        a.push_back(vec[i]);
    for(int i=m+1; i<=r; i++)
        b.push_back(vec[i]);
        
    int i=0,j=0;
    int x=a.size(),y=b.size();
    int crt=l;
    
    // 1 2 4
    // 3 5 6
    while(i<x && j<y) {
        if(a[i]<=b[j]) {
            vec[crt++]=a[i++];
        } else {
            vec[crt++]=b[j++]; 
            ans+=x-i;
        } 
    } 
    
    while(i<x)
        vec[crt++]=a[i++];
    while(j<y)
        vec[crt++]=b[j++];
    
}

void msort(vector<int>& vec, int l, int r, int& ans) {
    if(l<r) {
        int m=l+(r-l)/2;
        msort(vec,l,m,ans);
        msort(vec,m+1,r,ans);
        merge(vec,l,r,ans);
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> vec;
    int t;
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
    int ans=0;
    msort(vec,0,n-1,ans);
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
