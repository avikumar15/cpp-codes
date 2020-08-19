#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout std::cout

using namespace std;

map<int,int> mmap;

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void solve() {

    string str1,str2;
    
    cin>>str1>>str2;

    int n=str1.size();
    int m=str2.size();

    int count=0;
    int ind=0;

    int dp[m+1][n+1];

    for(int i=0; i<=m; i++) {
        dp[i][0]=i;
    }
    
    for(int i=0; i<=n; i++) {
        dp[0][i]=i;
    }

    for(int i=0; i<m; i++) {

        for(int j=0; j<n; j++) {
            
            if(str1[j]==str2[i]) {
                dp[i+1][j+1]=dp[i][j];
            } else {
                dp[i+1][j+1]=1+min({dp[i][j+1], dp[i+1][j], dp[i][j]});
            }
        }
    }

    // for(int i=0; i<=m; i++) {

    //     for(int j=0; j<=n; j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<dp[m][n]<<endl;

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
