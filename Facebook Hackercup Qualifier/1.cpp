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

    int n,m;
    int x;
    int k;
    int a,b,c,d;
    vi A,B;
    string str;
    string res="codeforces";
    map<char,int> mmap;
    vi vec;

    cin>>n;
    vi adj[n];
    adj[0].push_back(1);
    for(int i=1; i<n-1; i++) {
        adj[i].push_back(i-1);
        adj[i].push_back(i+1);
    }
    adj[n-1].push_back(n-2);

    string out;
    string in;

    cin>>in>>out;

    // if(in[0]=='N') {
    //     adj[1].erase()
    // }
    char G[n][n];

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            G[i][j]='Y';
        }
    }

    for(int i=0; i<in.size(); i++) {
        if(in[i]=='N') {
            for(int j=0; j<n; j++) {
                if(i==j)
                continue;
                G[j][i]='N';
            }
            for(int j=i+1; j<n; j++) {
                for(int k=i-1; k>=0; k--) {
                    G[k][j]='N';
                    G[j][k]='N';
                }
            }
        }
    }

    for(int i=0; i<out.size(); i++) {
        if(out[i]=='N') {
            for(int j=0; j<n; j++) {
                if(i==j)
                continue;
                G[i][j]='N';
            }
            for(int j=i+1; j<n; j++) {
                for(int k=i-1; k>=0; k--) {
                    G[k][j]='N';
                    G[j][k]='N';
                }
            }
        }
    }

    cout<<"Case #"<<cs++<<":\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<G[i][j];
        }
        cout<<endl;
    }

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
