#include<bits/stdc++.h>
#define int unsigned long long int
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
int32_t main() {    
    fastio;
    int t=1;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<(n*n+(n*(n+1)*(n-1))/6)<<endl;
    }
    return 0;
}
