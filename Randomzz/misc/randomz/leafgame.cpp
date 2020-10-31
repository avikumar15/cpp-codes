#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)
#define cout cout<<setprecision(15)
 
using namespace std;


void solve() {

    int n,x;

    cin>>n>>x;
    x--;

    vi adj[n];
    vi adjrev[n];
    int num[n];
    int temp1,temp2;

    FORN(0,n-1) 
        num[i]=0;

    FORN(0,n-2) {
        cin>>temp1>>temp2;
        temp1--;
        temp2--;
        adj[temp1].push_back(temp2);
        adjrev[temp2].push_back(temp1);
        num[temp1]++;
        num[temp2]++;
    }

    int sum=0;
    int root=0;

    FORN(0,n-1) {
        if(adj[i].size()==0)
        root=i;
    }

    while(1) {
        int count=0;
        int isFound=0;
        for(int i=0; i<n; i++) {
            if(num[i]==1 || (i==root && num[i]==0) ) {
                count++;
                num[i]--;
                for(int kk=0; kk<adjrev[i].size(); kk++) {
                    num[adjrev[i][kk]]--;
                }
            }
            if( num[i]==1 && i==x) 
                isFound=1;    
        }

        if(isFound==1) {
            if(sum%2==0) {
                cout<<"Ayush\n";
            } else {
                cout<<"Ashish\n";
            }
            break;
        }
        sum+=count;

    }

}
 
int32_t main() {
//    fastio;
 
    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
