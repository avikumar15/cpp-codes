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

    int a,b,x,y,n,mx,mn;

    cin>>a>>b>>x>>y>>n;

    if(max(a-n,x)>max(b-n,y)) {
        swap(a,b);
        swap(x,y);
    }

    // if(a>b || a==b && y<x) {
    //     swap(a,b);
    //     swap(x,y);
    // }
    
    int pa=a;
    a=max(x,a-n);
    n-=pa-a;

    b=max(y,b-n);
    
    // if(b-n>=y) {
    //     int pb=b;
    //     b=max(a,b-n);
    //     n-=pb-b;

    //     int l1=n/2, l2=n-n/2;

    //     int pa=a;
    //     a=max(x,a-l2);
    //     l2-=pa-a;
    //     l1+=l2;

    //     b=max(y,b-l1);
    // }
    // else {
    //     n-=b-y;
    //     b=y;


    // }

    cout<<a*b<<endl;

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
