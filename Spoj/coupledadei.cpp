#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

void solve() {
    int n;
    cin>>n;

    vi w,m;
    int temp1, temp2;

    for(int i=0; i<n; i++) {
        cin>>temp1;
        w.push_back(temp1);
    }
    sort(w.begin(), w.end());

    for(int i=0; i<n; i++) {
        cin>>temp1;
        m.push_back(temp1);
    }
    sort(m.begin(), m.end());

    int ans=0;

    for(int i=0; i<n; i++) {
        ans+=w[i]*m[i];
    }
    cout<<ans<<endl;
}

int32_t main() {
    fastio;

    int t;
    cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}