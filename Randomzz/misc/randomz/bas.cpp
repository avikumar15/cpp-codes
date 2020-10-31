#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout //cout<<setprecision(15)
 
using namespace std;

void dfs(vi adj[],vector<bool>& isVisited,int start, vi& result) {
    
    if(isVisited[start]) {
        return;
    }

    isVisited[start]=true;
    result.push_back(start);

    for(int i=0; i<adj[start].size(); i++) {
        dfs(adj,isVisited,adj[start][i],result);
    }

}

int log22(int b)
{
    int cnt = 0;
    while (b != 1)
    {
        if (b % 2 != 0)
            return -1;
        cnt++;
        b /= 2;
    }
    return cnt;
}


void solve() {
    int n; cin>>n;
    vi vex1,vex2;
    int temp;

    FORN(0,n-1) {
        cin>>temp;
        vex1.push_back(temp);
    }

    FORN(0,n-1) {
        cin>>temp;
        vex2.push_back(temp);
    }

    int dp1[n],dp2[n];
    dp1[0]=vex1[0];
    dp2[0]=vex2[0];

    FORN(1,n-1) {
        dp1[i]=max(dp1[i-1],dp2[i-1]+vex1[i]);
        dp2[i]=max(dp2[i-1],dp1[i-1]+vex2[i]);
    }

    // //cout<<endl;
//    //cout<<m1<<" "<<m2<<endl;
    cout<<max(dp1[n-1],dp2[n-1])<<endl;


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
