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

void solve() {

}
 
int32_t main() {
   fastio;

    float ans=0;

    // for(float i=2; i<10000; i++) {
    //     ans+=1/i;
    //     cout<<ans<<" ";        
    // }

    int t=10;
//    cin>>t;
 
    while(1) {

        int n;
        cin>>n;

        if(n==0) {
            break;
        }

        cout<<fixed<<setprecision(2)<<((n*n/(2*3.141592654)))<<endl;

    }
    return 0;
}
