#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

void multiply(int num, int res[MAX], int &size) {

    int carry=0;
    for(int i=0; i<size; i++) {
        int p = (carry+res[i]*num);
        res[i] = p % 10;
        carry = p/10;
    }
    int c=0;
    while(carry) {
        res[size]=carry%10;
        carry/=10;
        size++;
    }
}

void factorial(int N) {
    int res[MAX];

    for(int i=0; i<MAX; i++) {
        res[i]=0;
    }
    res[0]=1;

    int size=1;

    for(int i=2; i<=N; i++) {
        multiply(i,res,size);
    }
    for(int i=size-1; i>=0; i--) {
        cout<<res[i];
    }
    cout<<endl;
}

void solve() {
    int N;

    cin>>N;

    factorial(N);
}

int32_t main() {
    fastio;
    int t;
    cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}