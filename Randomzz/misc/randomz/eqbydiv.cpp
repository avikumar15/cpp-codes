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

    int n,k;
    cin>>n>>k;
    int temp;
    vi vec;
    int mx=LONG_LONG_MIN;

    FORN(0,n-1) {
        cin>>temp;
        vec.push_back(temp);
        mx=max(mx,temp);
    }

//    cout<<mx;
    int ans=0;    
    ans=LONG_LONG_MAX;

    for(int i=mx; i>=0; i++) {

        vi list;
        vi vec2=vec;

        for(int j=0; j<n; j++) {
            int cco=0;
            while(vec2[j]!=0 && vec2[j]!=i) {
                vec2[j]/=2;
                cco++;
            }
        //    cout<<cco<<" "<<vec2[j]<<" "<<i<<endl;
            if(vec2[j]==i) {
                list.push_back(cco);
            } else 
                continue;
        }
        if(list.size()>=k) {
            sort(list.begin(),list.end());
            int summ=0;
            for(int iii=0; iii<k; iii++) {
                summ+=list[iii];
            }
            ans=min(ans,summ);
        } else {
            continue;
        }
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
