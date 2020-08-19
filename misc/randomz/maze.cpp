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
    int n,m,k;
    cin>>n>>m>>k;
    char ch;
    char g[n][m];
    int arr[n][m];
    int count=0;
    vector<bool> isVisited;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>g[i][j];
            arr[i][j]=-1;
            if(g[i][j]=='.') {
                arr[i][j]=count;
                count++;
                isVisited.push_back(false);
            }
        }
    }

    vi adj[count];

    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            if(arr[i][j]!=-1) {
                if(arr[i][j+1]!=-1) {
                    adj[arr[i][j]].push_back(arr[i][j+1]);
                    adj[arr[i][j+1]].push_back(arr[i][j]);
                }
                if(arr[i+1][j]!=-1){
                    adj[arr[i][j]].push_back(arr[i+1][j]);
                    adj[arr[i+1][j]].push_back(arr[i][j]);
                }
            }
        }
    }

    for(int i=0; i<m-1; i++) {
        if(arr[n-1][i]!=-1) {
            if(arr[n-1][i+1]!=-1){
                adj[arr[n-1][i]].push_back(arr[n-1][i+1]);
                adj[arr[n-1][i+1]].push_back(arr[n-1][i]);    
            }
        }
    }

    for(int i=0; i<n-1; i++) {
        if(arr[i][m-1]!=-1) {
            if(arr[i+1][m-1]!=-1) {
                adj[arr[i][m-1]].push_back(arr[i+1][m-1]);
                adj[arr[i+1][m-1]].push_back(arr[i][m-1]);
            }
        }
    }

    // cout<<"**"<<endl;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"**"<<endl;

    // for(int i=0; i<count; i++) {
    //     cout<<i<<"-> ";
    //     for(int j=0; j<adj[i].size(); j++) {
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    vi result;

    dfs(adj,isVisited,0,result);
    vi finalsortof;

    // for(int i=0; i<result.size(); i++) {
    //     cout<<result[i]<<" ";
    // }
    // cout<<endl<<endl;


    for(int i=result.size()-1; i>=0; i--) {
        if(k>0) {
            k--;
            finalsortof.push_back(result[i]);
        }
    }

    sort(finalsortof.begin(),finalsortof.end());

    // for(int i=0; i<finalsortof.size(); i++) {
    //     cout<<finalsortof[i]<<" ";
    // }
    // cout<<endl;
    

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(arr[i][j]!=-1) {
                if(binary_search(finalsortof.begin(),finalsortof.end(),arr[i][j])) {
                    g[i][j]='X';
                }
            }
            cout<<g[i][j];
        }
        cout<<endl;
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