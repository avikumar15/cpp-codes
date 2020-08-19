#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout cout<<setprecision(15)
 
using namespace std;


void solve() {

    int n;
    vi A,B;
    map<int,int> mmap;
    int temp;

    cin>>n;

    FORN(0,n-1) {
        cin>>temp;
        A.push_back(temp);
        mmap[temp]=i+1;
    }

    FORN(0,n-1) {
        cin>>temp;
        B.push_back(temp);
    }

    for(int i=0; i<n; i++) {
        B.push_back(B[i]);
    }
    
    int ans=LONG_LONG_MIN;

    for(int i=0; i<2*n-1; i++) {
        int j=i;
        int s=1;
        int ss=mmap[B[i]];

        while( j<2*n-1 && mmap[B[j+1]]==ss+1) {
            j++;
            s++;
            ss=mmap[B[j]];
        }

        ans=max(ans,s);
        i=j;
    }

    cout<<ans<<endl;

}
 
int32_t main() {
//    fastio;
 
    int t=1;
//    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}