#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout cout<<setprecision(15)
 
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
 
void solve() {
    int n,m;
    cin>>n;
 
    vi vex1,vex2;
    vi merged;
    int temp;
 
    FORN(0,n-1) {
        cin>>temp;
        vex1.push_back(temp);
        merged.push_back(temp);
    }
 
    cin>>m;
    FORN(0,m-1) {
        cin>>temp;
        vex2.push_back(temp);
        merged.push_back(temp);
    }
 
    sort(vex1.begin(),vex1.end());
    sort(vex2.begin(),vex2.end());
    sort(merged.begin(),merged.end());
 
 
    int a1,a2;
    int mx=LONG_LONG_MIN;
    int deb;
 
    for(int i=0; i<merged.size(); i++) {
        // cout<<merged[i]<<" ";
        int u1=upper_bound(vex1.begin(),vex1.end(),merged[i])-vex1.begin();
        int u2=upper_bound(vex2.begin(),vex2.end(),merged[i])-vex2.begin();
        // cout<<mx<<" "<<(n-u1)*3+u1*2 - ((m-u2)*3+u2*2)<<" "<<merged[i]<<endl;
        if(mx<((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) || mx==((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) && a1<(n-u1)*3+u1*2) {
            a1=(n-u1)*3+u1*2;
            a2=(m-u2)*3+u2*2;
            mx=(n-u1)*3+u1*2 - ((m-u2)*3+u2*2);
            deb=merged[i];
        }
 
    }
    // cout<<endl;
 
    // cout<<a1<<":"<<a2<<endl;
 
    int u1=upper_bound(vex1.begin(),vex1.end(),merged[merged.size()-1]+5)-vex1.begin();
    int u2=upper_bound(vex2.begin(),vex2.end(),merged[merged.size()-1]+5)-vex2.begin();
 
    if(mx<((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) || mx==((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) && a1<(n-u1)*3+u1*2) {
        a1=(n-u1)*3+u1*2;
        a2=(m-u2)*3+u2*2;
        deb=merged[merged.size()-1]+5;
    }
 
    // cout<<a1<<":"<<a2<<endl;
 
    u1=upper_bound(vex1.begin(),vex1.end(),0)-vex1.begin();
    u2=upper_bound(vex2.begin(),vex2.end(),0)-vex2.begin();
 
    if(mx<((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) || mx==((n-u1)*3+u1*2 - ((m-u2)*3+u2*2)) && a1<(n-u1)*3+u1*2) {
        a1=(n-u1)*3+u1*2;
        a2=(m-u2)*3+u2*2;
        deb=0;
    }
    
    // cout<<deb<<endl;
    cout<<a1<<":"<<a2<<endl;
 
    // u1=upper_bound(vex1.begin(),vex1.end(),5)-vex1.begin();
    // u2=upper_bound(vex2.begin(),vex2.end(),5)-vex2.begin();
 
    // a1=(n-u1)*3+u1*2;
    // a2=(m-u2)*3+u2*2;
 
    // cout<<a1<<" "<<a2<<endl;
 
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