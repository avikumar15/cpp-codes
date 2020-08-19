#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
using namespace std;
vi DATA[10];
int32_t main() {
    DATA[0].push_back(0); int t; cin>>t;
    for(int i=1; i<=9; i++) {
        int temp=i;
        while(find(DATA[i].begin(),DATA[i].end(),temp)==DATA[i].end()) {
            DATA[i].push_back(temp); temp=(temp*i)%10;
        }
    }
    while(t--) {
        int n,k;
        cin>>n>>k;
        int ans= (k==0? 1:DATA[n%10][(k-1)%(DATA[n%10].size())]);
        cout<<ans<<endl;
    }
    return 0;
}