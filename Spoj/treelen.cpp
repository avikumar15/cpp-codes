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

int dfs(vi adj[], int start, vector<bool> isReached, vi &result) {
    
    if(isReached[start]) {
        return 0;
    }

    isReached[start]=true;
    int maxx=0;

    for(int i=0; i<adj[start].size(); i++) {
        maxx=max(maxx,(1+dfs(adj,adj[start][i],isReached,result)));
    }

    return maxx;
}

stack<int> anss;

void findVertexDepth(vi adj[], int start, vector<bool> isReached, vi &result, int counter) {
    
    if(isReached[start]) {
        return;
    }

    isReached[start]=true;
    result[start]=counter;

    for(int i=0; i<adj[start].size(); i++) {
        findVertexDepth(adj,adj[start][i],isReached,result,counter+1);
    }
}

void solve() {

    int n;
    cin>>n;

    int temp1,temp2;
    vi adj2[n];

    FORN(0,n-2) {
        cin>>temp1;
        cin>>temp2;

        temp1--;
        temp2--;

        adj2[temp1].push_back(temp2);
        adj2[temp2].push_back(temp1);
    }

    vector<bool> isReached(n,false);

    vi finalResult(n,0);
        
    findVertexDepth(adj2,0,isReached,finalResult,0);

    int maxDepthV=0;
    int maxx=INT_MIN;

    
    FORN(0,n-1) {
        if(finalResult[i]>maxx){
            maxx=finalResult[i];
            maxDepthV=i;
        }
    }

    // //cout<<endl<<v<<endl;
    int len=dfs(adj2,maxDepthV,isReached,finalResult);

    if(n==1)
        cout<<0<<endl;
    else
        cout<<len-1<<endl;

}
 
int32_t main() {
    
    fastio;

    int t=1;
//    cin>>t;
 
    while(t--) {
        solve();
    }

    return 0;
}
