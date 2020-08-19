#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
// #define cout cout<<setprecision(15)
 
using namespace std;

void solve() {
    int n;

    cin>>n;
    vi vec(n+5);

    for(int i=0;i<=n-1;i++) {
        cin>>vec[i+1];
    }

    set<int> sset;
    vi pref(n+5);
    pref[1]=vec[1];

    for(int i=2; i<=n; i++) {
        pref[i]=pref[i-1]+vec[i];
    }

    int l=0,h=0;
    int ans=0;
    sset.insert(0);

    while(l<n) {

        while(h<n && sset.count(pref[h+1])==0) {
            sset.insert(pref[h+1]);
            h++;
        }
        ans+=h-l;
        cout<<h<<" "<<l<<endl;
        sset.erase(pref[l]);
        l++;

    }

    cout<<ans<<endl;


}
 
int32_t main() {
    fastio;
 
    int t=1;
//    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
