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

vi sset;

void solve() {
    int l,r;
    cin>>l>>r;

    int cnt=0;

    int ind=0;

    for(;ind<sset.size(); ind++) {

        if(sset[ind]<=r && sset[ind]>=l)
        cnt++;

        if(sset[ind]>r)
        break;

        // cout<<sset[ind]<<" ";

    }

    cout<<cnt<<endl;

}
 
int32_t main() {
    fastio;

    int p = log2l(LONG_LONG_MAX/8);
    p=65;

    for(int l=0; l<p-5; l++) {
        for(int i=0; i<=l; i++) {
            for(int j=0; j<=l-i; j++) {

                int k=l-i-j;
                {
                    sset.push_back(pow(2,i+j+k+2)+pow(2,j+k+1)+pow(2,k));
                }
            }
        }
    }
    

    sort(sset.begin(),sset.end());

    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
