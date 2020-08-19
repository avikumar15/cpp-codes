#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;

map<int,int> mmap;

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int caseCount=1;

int valu(int n) {
    
    if(n<12)    return n;
    else return( valu(n/2)+valu(n/3)+valu(n/4) );

    // return max(n,( valu(n/2)+valu(n/3)+valu(n/4) ) );
    
}

void solve() {

    int n,k;
    int temp;
    // int a,b,c,d;

    // string str;
    // vector<string> strs;
    vi vec;

    // int m;

    cin>>n;
    int ans=0;

    for(int i=1; i*i<=(n); i++) {
        ans+=(n/i)-(i-1);
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
