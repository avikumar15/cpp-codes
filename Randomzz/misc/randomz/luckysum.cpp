#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
 
using namespace std;


void solve() {

    int n;
    cin>>n;
    int ncopy=n;
    int fu=1;

    // if(n%2==1) {
        int no7=0;
        int no4=0;

        while(n%7!=0 && n>=4) {
            n-=4;
            no4++;
        }
        if(n%7==0) {
            no7=n/7;
        } else {
            fu=-1;
            cout<<-1<<endl;
            return;
        }

        for(int i=0; i<no4; i++) {
            cout<<4;
        }
        for(int i=0; i<no7; i++) {
            cout<<7;
        }
        cout<<endl;
    // }

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
