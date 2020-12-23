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
    set<int> sset;
    vi dis;

    cin>>n>>k;
    int arr[n+5];

    for(int i=0; i<n+5; i++) {
        arr[i]=0;
    }

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
        if(sset.count(temp)==0) {
            sset.insert(temp);
            dis.push_back(temp);
        }
        arr[temp]=1;
    }

    vi leftover;

    if(sset.size()>k) {
        cout<<-1<<endl;
        return;
    }
    
    // cout<<"val of arr:\t";
    // for(int i=0;i<n+5; i++) {
    //     if(arr[i]==0) {
    //         cout<<arr[i]<<" ";
    //     }
    // }
    // cout<<endl;

    for(int i=1; i<=n; i++) {
        // if(dis.size()==k) {
        //     break;
        // }
        if(arr[i]!=1) {
            leftover.push_back(i);
            dis.push_back(i);
        }
    }

    cout<<n*k<<endl;

    // for(int i=0;i<dis.size(); i++) {
    //     cout<<dis[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0; i<n; i++) {
        for(int j=0; j<k; j++) {
            cout<<dis[j]<<" ";
        }
    }
    cout<<endl;






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
