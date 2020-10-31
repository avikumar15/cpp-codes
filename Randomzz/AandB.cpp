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

    int a,b;

    cin>>a>>b;

    int mn,mx;

    mn=min(a,b);
    mx=max(a,b);

    int diff1 = mx-mn;
    int diff2 = mx-mn;

    int i=0;

    for(;i<pow(10,6); i++) {
        if(i*(i+1)/2 >= diff1)
            break;
    }

    //cout<<i<<" "<<diff<<" ";
    // int ans1,ans2;

    // //if(diff!=i*(i+1)/2){
    //     diff1-=i*(i-1)/2;
    //     ans1=i-1;
    // //}
    // //else {
    //     diff1-=i*(i+1)/2;
    //     ans2=i;
    // //}
    
    // cout<<ans1<<" "<<diff1<<" "<<endl<<ans2<<" "<<diff2<<endl;

    // ans1+=abs(diff1)*2;
    // ans2+=abs(diff2)*2;

    // cout<<min(ans1,ans2)<<endl;

    //cout<<i<<" "<<i*(i+1)/2<<" "<<diff1<<endl;

    if(i*(i+1)/2 % 2 != diff1 % 2 && i%2==0)
        i++;
    else if(i*(i+1)/2 % 2 != diff1 % 2)
        i+=2;

    cout<<i<<endl;
    

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
