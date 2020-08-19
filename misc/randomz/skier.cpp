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

    string str;
    cin>>str;

    map<pair<pair<int,int>,pair<int,int>>,bool> mmap;
//    mmap[make_pair(0,0)]=1;
    int ans=0;
    int x=0;
    int y=0;

    for(int i=0; i<str.size(); i++) {
        if(str[i]=='N') {
            if(mmap[make_pair(make_pair(x,y),make_pair(x,y+1))]==1) {
                ans+=1;
            }
            else 
            ans+=5;
            y++;
            mmap[make_pair(make_pair(x,y),make_pair(x,y-1))]=1;
            mmap[make_pair(make_pair(x,y-1),make_pair(x,y))]=1;
        } else if(str[i]=='S') {
            if(mmap[make_pair(make_pair(x,y-1),make_pair(x,y))]==1) {
                ans+=1;
            }
            else 
            ans+=5;
            y--;
            mmap[make_pair(make_pair(x,y),make_pair(x,y+1))]=1;
            mmap[make_pair(make_pair(x,y+1),make_pair(x,y))]=1;
        } else if (str[i]=='W') {
            if(mmap[{{x-1,y},{x,y}}]==1) {
                ans+=0*4+1;
                //x--;
            }
            else 
            ans+=5;
            x--;
            mmap[{make_pair(x,y),make_pair(x+1,y)}]=1;
            mmap[{make_pair(x+1,y),make_pair(x,y)}]=1;
        } else {
            if(mmap[{make_pair(x+1,y),make_pair(x,y)}]==1) {
                ans+=0*4+1;
                //x++;
            }
            else 
            ans+=5;
            x++;
            mmap[{make_pair(x,y),make_pair(x-1,y)}]=1;
            mmap[{make_pair(x-1,y),make_pair(x,y)}]=1;
        }
    }

    cout<<ans<<endl;

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
