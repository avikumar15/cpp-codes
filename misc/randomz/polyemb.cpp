#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout cout<<setprecision(25)
#define PI 4*atan(1)
 
using namespace std;


void solve() {

    long double n;
    cin>>n;

    n*=2.0;
    long double ans=0.0;

    ans = 1/tan(PI/n);

    cout<<ans<<endl;

}
 
int32_t main() {
    //fastio;
 
    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
