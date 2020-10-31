#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;

void buildSegTree(vector<int> arr, vector<int> tree, int index, int s, int e) {
    
    if(s>e)
        return;
    
    if(s==e) {
        tree[s]=arr[index];
        return;
    }

    int mid=(s+e)/2;

    buildSegTree(arr,tree,2*index,s,mid);
    buildSegTree(arr,tree,2*index+1,mid+1,e);
    
    if(tree[2*index]<=0 || tree[2*index+1]<=0)
        tree[index]=max({tree[2*index],tree[2*index+1]});
    else
        tree[index]=tree[2*index]+tree[2*index];

}

int query(vector<int> tree, int s, int e, int index, int qs, int qe) {
    if(qe<s || qs>e)
        return INT_MIN;

    if(qe>=e && qs<=s) {
        return tree[index];
    }

    int mid=(s+e)/2;
    int left = query(tree, s, mid, 2*index, qs, qe);
    int right = query(tree, mid+1, e, 2*index+1, qs, qe);

    return max(left,right);
}

void solve() {

    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> tree(4*n+5);

    // -1 2 3

    for(int i=0; i<n; i++)
        cin>>arr[i];

    buildSegTree(arr,tree,1,0,n-1);

    int q;
    cin>>q;

    while(q--) {

        int l,r;
        cin>>l>>r;

        int ans = query(tree,0,n-1, 1, l,r);
        cout<<ans<<endl;

    }

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
