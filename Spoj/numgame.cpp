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
    cin>>n;

    if(n%10==0) {
        cout<<2<<endl;
    } else {
        cout<<1<<endl<<n%10<<endl;
    }

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
