#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(15)
 
using namespace std;

bool primes[100005];
vector<int> prime;

void sieve(int n) {

    primes[2] = false;
    for (int i = 2; i * i <= 100000; i++) {
        if (primes[i] == false) {
            for (int p = i * i; p <= 100000; p += i) {
                primes[p] = true;
            }
        }
    }
    for (int i = 2; i <= 100000; i++) {
        if (primes[i] == false)
            prime.push_back(i);
    }
}

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

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(0,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(0,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int log22(int b) {

    int cnt = 0;
    while (b != 1) {
        cnt++;
        b /= 2;
    }
    return cnt;
}

void inVec(vi &vec, int n) {
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
}

int cs=1;

void solve() {

    int n,k;

    cin>>n>>k;
    vector<int> vec;
    int temp;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    for(int i=0; i<n; i++)
        cin>>temp;

    sort(vec.begin(),vec.end());
    
    int mxl[n+5], mxr[n+5];
    int mx = 0;
    mxr[n] = 0;

    mxl[0] = 1;
    mxr[n-1] = 1;

    for(int i=1; i<n; i++) {
        int lb = lower_bound(vec.begin(),vec.end(),vec[i]-k)-vec.begin();
        mxl[i]=max(mxl[i-1],i-lb+1);
    }


    for(int i=n-2; i>=0; i--) {
        int lb = upper_bound(vec.begin(),vec.end(),vec[i]+k)-vec.begin();
        mxr[i]=max(mxr[i+1],lb-i);
    }

    for(int i=0; i<n; i++) {
        // cout<<mxl[i]<<" ";
        mx = max(mx,mxl[i]+mxr[i+1]);
    }

//    cout<<endl;

    // for(int i=0; i<n; i++) {
    //     // cout<<mxr[i]<<" ";
    //     //mx = max(mx,mxl[i]+mxr[i+1]);
    // }

//    cout<<endl;

    cout<<mx<<endl;

    

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
