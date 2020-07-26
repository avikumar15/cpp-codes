#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int power(int a, int p, int m) {

    if(p==0) {
        return 1;
    }
    if(p==1) {
        return a%m;
    }
    if(a==1) {
        return 1;
    }

    int val = (power(a,p/2,m)%m);
    
    if(p%2==1) {
        return ((((val%m)*(val%m)%m)*(a%m))%m);
    } else {
        return (((val%m)*(val%m))%m);
    }

}

int modinverse(int a,int b,int m) {
    return (((a%m)*(power(b,m-2,m)))%m);
}

int mmap[1005][1005];

int ncr(int n, int r) {

    if(n<r) {
        return 0;
    }

    if(mmap[n][r]!=-1) {
        return mmap[n][r];
    }

    if(n==r || r==0) {
        mmap[n][r]=1;
        mmap[n][n-r]=1;
        return 1;
    }

    int val = (ncr(n-1,r-1)%mod + ncr(n-1,r)%mod)%mod;
    mmap[n][r]=val;
    mmap[n][n-r]=val;
    return val; 

}

int32_t main() {

    for(int i=0; i<1002; i++) {
        for(int j=0; j<1002; j++) {
            mmap[i][j]=-1;
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n=50;
    int r=25;

    int t=1;
    cin>>t;

    while(t--) { 
        cin>>n>>r;
        int ans = ncr(n,r);
        cout<<ans<<endl;
    }

}
