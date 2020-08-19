#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

void solve(int N) {
    cout<<N*(N+1)*(2*N+1)/6 <<endl;
}

int32_t main() {
    fastio;

    int temp;

    while(1) {
        cin>>temp;

        if(temp==0)
        break;

        solve(temp);
    }
    return 0;
}