/**
 * This code belongs to Avi (106118017)
*/
#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
 
using namespace std;

void vecInput(vi &vec, int n) {
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
}

int number(vector<vector<char>> inp, map< pair <pair<int,int>,pair<int,int>>,int> &mmap, int r, int c, int lastr, int lastc, bool isOdd) {

    // cout<<r<<" "<<c<<" "<<lastr<<" "<<lastc<<endl;

    if(r>lastr || c>lastc) {
        return 0;
    }

    if(mmap[{{r,c},{lastr,lastc}}]!=-1) {
        return mmap[{{r,c},{lastr,lastc}}];
    }

    if(inp[r][c]==inp[lastr][lastc] || (isOdd && r==lastr && c==lastc)) {

        if(abs(r-lastr)+abs(c-lastc)==0 || abs(r-lastr)+abs(c-lastc)==1) {
            mmap[{{r,c},{lastr,lastc}}]=1;
            return 1;
        }
        
        int n1=number(inp,mmap,r+1,c,lastr-1,lastc,isOdd);
        int n2=number(inp,mmap,r+1,c,lastr,lastc-1,isOdd);
        int n3=number(inp,mmap,r,c+1,lastr-1,lastc,isOdd);
        int n4=number(inp,mmap,r,c+1,lastr,lastc-1,isOdd);
        // cout<<"ns are "<<n1<<" "<<n2<<" "<<n3<<" "<<n4<<endl;

        mmap[{{r,c},{lastr,lastc}}]=n1+n2+n3+n4;
    } else {
        mmap[{{r,c},{lastr,lastc}}]=0;
    }

    return mmap[{{r,c},{lastr,lastc}}];

}
 
void solve() {

    int n;
    int m;

    cin>>n>>m;

    vector<vector<char>> inp;
    map< pair <pair<int,int>,pair<int,int>>,int> mmap;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int a=0; a<n; a++) {
                for(int b=0; b<m; b++) {
                    mmap[make_pair(make_pair(i,j),make_pair(a,b))]=-1;
                }
            }
        }
    }

    string str="";

    for(int i=0; i<n; i++) {
        vector<char> temp;
        for(int j=0; j<m; j++) {
            char c;
            cin>>c;
            temp.push_back(c);
        }
        inp.push_back(temp);
    }
    bool isOdd=(n+m)%2==1;
    int ans = number(inp,mmap,0,0,n-1,m-1,isOdd);

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
