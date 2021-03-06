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

    inVec(vec,n);

    int pref[n];

    sort(vec.begin(), vec.end());

    pref[0] = vec[0];

    for(int i=1; i<n; i++) {
        pref[i] = pref[i-1];
        pref[i] += vec[i];
    }

    int tot = pref[n-1];

    int rad = k/2;

    int ans = LONG_LONG_MAX;

    for(int p=0; p<n; p++) {

        int i = vec[p];
        int temp = 0;

        int justAhead = upper_bound(vec.begin(), vec.end(), (vec[p]+rad)%k) - vec.begin() - 1;
        
        if(vec[p] + rad > k) {
            temp += pref[n-1] - pref[p] -i*(n-1-p);
            if(justAhead != -1) {
                temp += pref[p] - 
            }

        } else {
            temp += pref[justAhead] - pref[p] - i*(justAhead-p);
            if(p != 0) {
                temp += i*p - pref[p-1];
            }
            if(justAhead != n-1) {
                temp += (n-1-justAhead)*k - (pref[n-1] - pref[justAhead]) + i*(n-1-justAhead);
            }
        }
        
        //cout<<temp<<" ";
        ans=min(temp,ans);
    }
    cout<<endl;

    if(n==0) {
        cout<<"CASE #"<<cs++<<": "<<0<<endl;
        return;
    }

    cout<<"CASE #"<<cs++<<": "<<ans<<endl;
    

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
