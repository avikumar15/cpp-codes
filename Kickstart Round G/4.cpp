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

int catalan(unsigned int n)
{
    // Base case
    if (n <= 1) return 1;
 
    // catalan(n) is sum of catalan(i)*catalan(n-i-1)
    int res = 0;
    for (int i=0; i<n; i++)
        res += catalan(i)*catalan(n-i-1);
 
    return res;
}

void solve() {

    int n,k;
    cin>>n;

    vi vec;
    inVec(vec,n);

    int dp[n+25][n+25];

    for(int i=0; i<n; i++)
        dp[i][i]=vec[i];
    
    for(int i=0; i<n-1; i++)
        dp[i][i+1]=vec[i]+vec[i+1];

    long double total_sum=0.0;
    long double deno=0.0;

    for(int i=2; i<n; i++) {
        int ci=i;

        for(int j=0; j<n-i; j++) {
            dp[j][ci]=dp[j+1][ci]+dp[j][ci-1];
            ci++;
            //total_sum+=dp[j][ci-1]*;
            //deno+=
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            cout<<dp[i][j]<<" ";
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
