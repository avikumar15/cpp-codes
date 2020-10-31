/**
 * This code belongs to Avi (106118017)
*/
#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
using namespace std;

void vecInput(vi &vec, int n) {
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
}
 
void solve() {

    int n;
    vi vec;
    cin>>n;
    int x;
    int temp;
    cin>>x;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    int l=lower_bound(vec.begin(),vec.end(),x)-vec.begin();
    int h=upper_bound(vec.begin(),vec.end(),x)-vec.begin();

    if(l!=n && h!=0)
    cout<<l<<" "<<h-1<<endl;
    else 
    cout<<-1<<endl;
    
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
