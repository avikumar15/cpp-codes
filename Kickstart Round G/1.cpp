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
    string str;
    string res="";

    cin>>str;
    
    n = str.size();

    for(int i=0; i<n; i++) {
        if(i+3<n) {
            if(str[i]=='K' && str[i+1]=='I' && str[i+2]=='C' && str[i+3]=='K') {
                res+='K';
            }
        }
        if(i+4<n) {
            if(str[i]=='S' && str[i+1]=='T' && str[i+2]=='A' && str[i+3]=='R' && str[i+4]=='T') {
                res+='S';
            }
        }
    }

    int ans = 0;
    n = res.size();
    
    vector<int> SAfter(n+5,0);
    SAfter[n]=0;

    for(int i=n-1; i>=0; i--) {
        SAfter[i]=SAfter[i+1];
        if(res[i]=='S')
            SAfter[i]++;
    }

    for(int i=0; i<n; i++) {
        if(res[i]=='K')
            ans+=SAfter[i];
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
