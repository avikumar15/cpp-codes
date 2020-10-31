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
    cin>>n;

    vector<int> vec;

    for(int i=0; i<n; i++) {
        int temp;

        cin>>temp;
        vec.push_back(temp);
    }

    int psum[n+5];
    psum[0]=0;
    

    for(int i=0; i<n; i++) {
        psum[i+1]=psum[i]+vec[i];
    }

    n++;
    
    vector<pair<int,int>> vpp;
    map<int,int> lastOcc;
    
    for(int i=0; i<n; i++) {
        if(lastOcc.find(psum[i])==lastOcc.end()) {
            lastOcc[psum[i]]=i;
            continue;
        }
        vpp.push_back({lastOcc[psum[i]]+1,i-1});
        lastOcc[psum[i]]=i;
    }

    // for(int i=0; i<vpp.size(); i++) 
    //     cout<<vpp[i].first<<" "<<vpp[i].second<<"\n";

    sort(vpp.begin(),vpp.end());

    int ans=0;

    n = vpp.size();

    if(n==0) {
        cout<<0<<endl;
        return;
    }
    
    vector<int> is(n,0);
    is[0]=0;

    if(n!=0)
        ans++;

    int e = vpp[0].second;

    int a = n;
    
    for(int i=1; i<n; i++) {
        // if(is[i-1]==0 && vpp[i].first<=vpp[i-1].second){
        //     is[i]=1;
        //     continue;
        // }
        // else {
        //     ans++;
        //     is[i]=0;
        // }

        if(vpp[i].first<=e) {
            a--;
            e = min(e,vpp[i].second);
        }

        else {
            ans++;
            e = vpp[i].second;

        }
        

    }

    cout<<ans<<endl;


}
 
int32_t main() {
    fastio;
 
    int t=1;
    //cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
