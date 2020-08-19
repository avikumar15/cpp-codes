#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

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

int caseNo=1;

void solve() {

    int n;
    vi vec;

    cin>>n;
    
    vi dp;

    int temp;

    FORN(0, n-1) {
        cin>>temp;
        vec.push_back(temp);
    }

    // dp[0]=vec[0];
    // dp[1]=max(vec[0],vec[1]);

    if(n==0) {
        cout<<"Case "<<caseNo++<<": "<<0<<endl;
    } else {
        
        if(n==1) {
            cout<<"Case "<<caseNo++<<": "<<vec[0]<<endl;
        } else {
            dp.push_back(vec[0]);
            dp.push_back(max(vec[0],vec[1]));

            FORN(2,n-1) {
                dp.push_back(max((dp[i-2]+vec[i]),dp[i-1]));
            }
 
            cout<<"Case "<<caseNo++<<": "<<dp[n-1]<<endl;
        }

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
