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

//     for(int i=0; i<10000; i++) {
//         if(i*i*i%1000==888) {
//             cout<<i<<" ";
//         }
//     }

    int t=10;
    cin>>t;
 
    while(t--) {

        int k;
        cin>>k;

        int fr=(k-1)/4;
        int fu=k%4;

        int ans=fr*1000;

        if(fu==1) {
            ans+=192;
        } else if(fu==2) {
            ans+=442;
        } else if(fu==3) {
            ans+=692;
        } else {
            ans+=942;
        }

        cout<<ans<<endl;

    }

    return 0;
}
