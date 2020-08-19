#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod2 1000000007
#define mod 1000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;


void solve() {

    int n;
    cin>>n;

    int ans=((n%mod)*((n+1)%mod))%mod;

    if(n%2==0)
    ans+=(((n/2)%mod)*((n-1)%mod))%mod;
    else 
    ans+=(((n)%mod)*(((n-1)/2)%mod))%mod;

    cout<<(ans)%mod<<endl;


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
