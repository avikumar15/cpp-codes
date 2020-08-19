#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
// #define cout cout<<setprecision(15)
 
using namespace std;
 
// bool primes[100005];
// vector<int> prime;
 
// void sieve(int n) {
 
//     primes[2] = false;
//     for (int i = 2; i * i <= 100000; i++) {
//         if (primes[i] == false) {
//             for (int p = i * i; p <= 100000; p += i) {
//                 primes[p] = true;
//             }
//         }
//     }
//     for (int i = 2; i <= 100000; i++) {
//         if (primes[i] == false)
//             prime.push_back(i);
//     }
// }
 
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
 
void solve() {
 
    int n;
    int a,b,c,d;
    int temp;
    int temp2;
    int temp3;
    string str;
    string res="";
    vi vec;
    int k;

    cin>>n;
    inVec(vec,n);
    int ans=0;
    vector<pair<int,int>> vpp;
    int mx=vec[0];
    int dpmaxback[n+5];
    dpmaxback[n-1]=vec[n-1];
    set<int> setbackdis;
    vi countFromBack(n+5);

    setbackdis.insert(vec[n-1]);
    countFromBack[n-1]=(1);

    for(int i = n-2; i>=0; i--) {
        dpmaxback[i]=max(dpmaxback[i+1],vec[i]);
        if(setbackdis.count(vec[i])==0)
            setbackdis.insert(vec[i]);
        countFromBack[i]=(setbackdis.size());
    }

    // printVector(countFromBack);

    vi count2(n+5,0);

    for(int i=0; i<n-1; i++) {
        mx=max(mx,vec[i]);
        count2[vec[i]]++;
        if(count2[vec[i]]>1) {
            break;
        }
        if(mx==i+1){ //&& dpmaxback[i+1]==n-i-1 && countFromBack[i+1]==n-i-1) {
            
            ans++;
            vpp.push_back({i+1,n-i-1});
        }
    }
    
    vector<pair<int,int>> vpp2;
    vi count3(n+5,0);
    mx=vec[n-1];

    set<pair<int,int>> sset;

    for(int i=n-1; i>0; i--) {
        mx=max(mx,vec[i]);
        count3[vec[i]]++;
        if(count3[vec[i]]>1)
            break;

        if(mx==n-i) {
            sset.insert({i,n-i});
        }

    }

    ans=0;

    for(int i=0; i<vpp.size(); i++) {
        if(sset.count({vpp[i].first,vpp[i].second})==1) {
            ans++;
        }
    }

    cout<<ans<<endl;
    for(int i=0; i<vpp.size(); i++) {
        if(sset.count({vpp[i].first,vpp[i].second})==1)
        cout<<vpp[i].first<<" "<<vpp[i].second<<endl;
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
