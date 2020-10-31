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
    int temp;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    int l=0;
    int h=n-1;
    int m=l+(h-l)/2;

    while(h>l+1) {
        m=l+(h-l)/2;
        // cout<<l<<" "<<m<<" "<<h<<endl;
        // if(vec[m]>=vec[l]) {
        //     l=m;
        // } else { 
        //     h=m;
        // }

        if(vec[m]>vec[m-1] && vec[m]>vec[m+1]) {
            break;
        } else {
            if(vec[m]>vec[m-1]) {
                l=m;
            } else {
                h=m;
            }
        }

    }

    if( (l==0 && vec[l]>vec[l+1]) || (vec[l]>vec[l+1] && vec[l]>vec[l-1])) {
        cout<<vec[l]<<endl;
        return;
    }

    if( (m==0 && vec[m]>vec[m+1]) || vec[m]>vec[m+1] && vec[m]>vec[m-1]) {
        cout<<vec[m]<<endl;
        return;
    }

    cout<<vec[h]<<endl;

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
