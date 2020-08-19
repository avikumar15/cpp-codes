#include<bits/stdc++.h>
#define int unsigned long long int
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

void solve() {

    int a3,am3,sum;
    cin>>a3>>am3>>sum;

    int n=(2*sum)/(a3+am3);
    int d=((am3-a3)/(n-5));
    int a=a3-(2*d);

    cout<<n<<endl;
    FORN(0,n-1) {
        cout<<(a+(i*d))<<" ";
    }
    cout<<endl;

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
