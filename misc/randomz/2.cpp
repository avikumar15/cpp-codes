#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define cout cout<<setprecision(15)
 
using namespace std;

void solve() {

    map<char,char> mmap;

    mmap['x']='c';
    mmap['y']='b';
    mmap['z']='a';
    mmap['a']='z';

    for(int i=1; i<=26; i++) {
        mmap[char('a'+i)]=(char)('z'-i);
    }
    mmap[' ']=' ';

    string str="xyis yozxp zmw dsrgv";

    for(int i=0; i<str.size(); i++) {
        cout<<mmap[str[i]];
    }

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