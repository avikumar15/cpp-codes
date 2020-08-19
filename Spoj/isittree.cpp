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

int fu=0;
int ccount=0;

void dfs(vi adj[], vi& result, int parent, vector<bool> &isVisited) {

    if(isVisited[parent]) {
        fu=-1;
        return;
    }

    result.push_back(parent);
    isVisited[parent]=true;
    ccount++;

    for(int i=0; i<adj[parent].size(); i++) {
        dfs(adj,result,adj[parent][i],isVisited);
    }

}
 
int32_t main() {
//   fastio;

    float ans=0;

    // for(float i=2; i<10000; i++) {
    //     ans+=1/i;
    //     cout<<ans<<" ";        
    // }

    int t=10;
//    cin>>t;
 
    while(1) {

        int n;
        int v;

        cin>>n>>v;

        vi adj[n];
        int temp1, temp2;

        for(int i=0; i<v; i++) {
            
            cin>>temp1;
            cin>>temp2;
            
            temp1--;
            temp2--;

            adj[temp1].push_back(temp2);

        }

        // FORN(0,n-1) {
        //     for(int j=0; j<adj[i].size(); j++) {
        //         cout<<adj[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<bool> isReached;

        for(int i=0; i<n; i++) {
            isReached.push_back(false);
        }

        vi finalDfs;

        dfs(adj,finalDfs,0,isReached);

        if(fu==0 && ccount==n) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }

        // FORN(0,n-1) {
        //     cout<<finalDfs[i]<<" ";
        // }
        // cout<<endl;

        break;

    }

    return 0;
}
