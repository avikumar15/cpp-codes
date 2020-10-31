#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout //cout<<setprecision(15)
 
using namespace std;

int mx=LONG_LONG_MIN;
int fu=1;

void dfs(vi adj[],vector<bool>& isVisited,int start, string str, vi &result, vector<bool> isVisited2, map<char,int> mmap) {
    
    if(isVisited2[start]) {
        fu=-1;
        return;
    }
    if(isVisited[start]) {
        return;
    }

    mmap[str[start]]++;
    isVisited[start]=true;
    isVisited2[start]=true;
    result.push_back(start);

    if(adj[start].size()==0) {
        for(auto i:mmap) {
            mx=max(mx,i.second);
        }
    }

    for(int i=0; i<adj[start].size(); i++) {
        dfs(adj,isVisited,adj[start][i], str, result,isVisited2,mmap);
    }

}


void solve() {

    int n,m;
    cin>>n>>m;
    string str;
    cin>>str;
    int temp1,temp2;
    vi adj[n];

    FORN(0,m-1) {
        cin>>temp1;
        cin>>temp2;
        temp1--;
        temp2--;

        adj[temp1].push_back(temp2);

    }
    
    vector<bool> isVisited(n,false);
    vector<bool> isVisited2(n,false);
    vi results;


    int ss=0;

    map<char,int> mmap;

    while(ss<n) {
        if(!isVisited[ss]) {
            dfs(adj,isVisited,ss,str,results,isVisited2, mmap);
        }
        mmap.clear();
        ss++;
    }

    // cout<<endl;
    // FORN(0,results.size()-1) {
    //     cout<<results[i]<<" ";
    // }
    // cout<<endl;

    if(fu==1)
    cout<<mx<<endl;
    else 
    cout<<-1<<endl;

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
