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

    cin>>str;
    n=str.size();

    for(int i=0; i<n; i++) {
        if(str[i]=='m' || str[i]=='w') {
            cout<<0<<endl;
            return;
        }
    }

    int dp[100000+50];

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;

    for(int i=4; i<100000+50; i++) {
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    
    int ans=1;
    int flag=0;

    for(int i=0; i<n; i++) {
        int j=i;
        if(str[i]=='u') {
            while(j+1<n && str[j+1]==str[i]) 
                j++;
            // if(j==i)
            //     continue;
            ans*=(dp[j-i+1])%mod;
            ans%=mod;
            flag=1;
        } else if(str[i]=='n') {
            while(j+1<n && str[j+1]==str[i]) 
                j++;
            // if(j==i)
            //     continue;
            ans*=(dp[j-i+1])%mod;
            ans%=mod;
            flag=1;
        }
        i=j;
    }
    
    if(flag==0)
        cout<<1<<endl;
    else
        cout<<ans%mod<<endl;

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
