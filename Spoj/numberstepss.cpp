#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

void solve() {
    int x,y;

    cin>>x>>y;
    int m = x%2;

    if((y==x-1) || (y>x) || x-2>y) {
        cout<<"No Number"<<endl;
    }
    else {
        if(m==0) {
            int first=2*x;
            int second=2*x-2;

            if(y*2<second) {
                cout<<second<<endl;
            } else {
                cout<<first<<endl;
            } 
        } else {
            int first = x*2-1;
            int second = x*2-3;

            if(y*2<second) {
                cout<<second<<endl;
            } else {
                cout<<first<<endl;
            }
        }
    }
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