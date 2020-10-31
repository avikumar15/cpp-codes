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

    vi done(n+5,0);
    vi vecCorrect(n+5,0);

    for(int i=0; i<n; i++) {
        vecCorrect[vec[i]]=i+1;
    }

    int last=n;
    int end=n+1;
    int start=n;
    int fu=1;

    for(int i=1; i<=n; i++) {

        if(i==1) {
            done[vecCorrect[i]]=1;
            last=vecCorrect[i];
            if(vecCorrect[i]==end-1)
            end--;
            continue;
        }
        if(last==end) {
            done[vecCorrect[i]]=1;
            last=vecCorrect[i];
            if(vecCorrect[i]==end-1){
                while(end>0 && done[end-1]==1)
                end--;
                last=end;
            } 
        } else {
            if(vecCorrect[i]==last+1) {
                done[vecCorrect[i]]=1;
                last=vecCorrect[i];
                if(vecCorrect[i]==end-1){
                    while(end>0 && done[end-1]==1)
                    end--;
                    last=end;
                } 
            } else {
                fu=-1;
                break;
            }
        }
    }

    if(fu==-1) {
        cout<<"No\n";
    } else {
        cout<<"Yes\n";
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
