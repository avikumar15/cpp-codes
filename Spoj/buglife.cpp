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

int caseNo=1;

bool isBipartite(vi adj[], vector<bool>& isVisited,char arr[], int start, int gender, int parent) {

    if(gender%2==0) {
        if(arr[start]=='F')
            return false;
        if(isVisited[start])
            return true;
        arr[start]='M';
    }
    else {
        if(arr[start]=='M')
            return false;
        if(isVisited[start])
            return true;
        arr[start]='F';
    }

    isVisited[start]=true;

    for(int i=0; i<adj[start].size(); i++) {
        if(adj[start][i]==parent) {
            continue;
        }
        if(isBipartite(adj,isVisited,arr,adj[start][i],gender+1,start)) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void solve() {
    int n,k;
    cin>>n>>k;
    char arr[n+5];
    
    vi adj[n+5];
    vector<bool> isVisited(n+5,false);

    FORN(0,n+5) {
        arr[i]='N';
    }

    int temp1,temp2;
    int f=1;

    for(int i=0; i<k; i++) {
        cin>>temp1;
        cin>>temp2;

        temp1--;
        temp2--;

        adj[temp1].push_back(temp2);
        adj[temp2].push_back(temp1);

    }
    
    bool result=true;
    int noOfV=0;

    while(result && noOfV<n) {
        if(!isVisited[noOfV])
        result = isBipartite(adj,isVisited,arr,noOfV,0,-1);
        noOfV++;
    }

    cout<<"Scenario #"<<caseNo++<<":\n";
    if(!result) {
        cout<<"Suspicious bugs found!\n";
    } else {
        cout<<"No suspicious bugs found!\n";
    }

}
 
int32_t main() {
    fastio;
 
    int t=10;
    cin>>t;
    
    while(t--) {
        solve();
    }
    return 0;
}
