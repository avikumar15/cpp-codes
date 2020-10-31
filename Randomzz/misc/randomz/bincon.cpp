#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(25)
#define PI 4*atan(1)
 
using namespace std;


void solve() {

    int n0,n1,n2;
    char last;

    cin>>n0>>n1>>n2;

    string res="";

    last='-';

    if(n1>0){
        res+='0';
        last='0';
    }


    for(int i=0; i<n1-1; i++) {
        if(res[res.size()-1]=='0')
            res+='1';
        else 
            res+='0';
        last=res[res.size()-1];
    }

    if(last=='0') {
        //if(n0!=0) {
            for(int i=0; i<n0; i++) {
                res+='0';
            }
            // if(n2!=0)
            res+='1';
            for(int i=0; i<n2; i++) {
                res+='1';
            }
        // } else {
        //     res+='1';
        // }
    } else {
        for(int i=0; i<n2; i++) {
            res+='1';
        }
        if(last=='-' && n2!=0) {
            res+='1';
        }

        if(last!='-' || n0!=0)
        res+='0';

        for(int i=0; i<n0; i++) {
            res+='0';
        }
    }


    cout<<res<<endl;

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


