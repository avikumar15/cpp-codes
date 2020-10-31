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
    string res=str;

    int x;
    cin>>x;

    n=str.size();

    // 101110
    // 110

    for(int i=0; i<n; i++)
        res[i]='-';

    for(int i=0; i<n; i++) {
        if(str[i]=='0') {
            if(i-x>=0)
                res[i-x]='0';
            if(i+x<n)
                res[i+x]='0';
        }
    }
    
    int f=1;

    for(int i=0; i<n; i++) {
        int ff=1;
        if(str[i]=='1') {
            if(i-x>=0) {
                if(res[i-x]=='-')
                    res[i-x]='1';
                else if(res[i-x]=='0'){
                    ff=0; 
                    if(!(i+x<n))
                        f=-1;
                }
            }
            if(i+x<n) {
                if(res[i+x]=='-')
                    res[i+x]='1';
                else if(res[i+x]=='0' && (ff==0 || !(i-x>=0))) {
                    f=-1;
                }
            }
            if(i-x<0 && i+x>=n)
                f=-1;
        }

        //cout<<"res now "<<res<<endl;

        if(f==-1)
            break;
    }

    for(int i=0; i<n; i++)
        if(res[i]=='-')
            res[i]='1';
    
    
    if(f==-1)
        cout<<-1<<endl;
    else 
        cout<<res<<endl;

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
