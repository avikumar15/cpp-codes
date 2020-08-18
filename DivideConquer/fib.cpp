#include <bits/stdc++.h>
#define int long long
#define vvi vector<vector<int>>
#define mod 1000000007

using namespace std;

int MM(int a) {
    return a%mod;
}

void multiply(vvi &mat, vvi mat2) {
    int a,b,c,d;
    a=MM(MM(MM(mat[0][0])*MM(mat2[0][0]))+MM(MM(mat[0][1])*MM(mat2[1][0])));
    b=MM(MM(MM(mat[0][0])*MM(mat2[0][1]))+MM(MM(mat[0][1])*MM(mat2[1][1])));
    c=MM(MM(MM(mat[1][0])*MM(mat2[0][0]))+MM(MM(mat[1][1])*MM(mat2[1][0])));
    d=MM(MM(MM(mat[1][0])*MM(mat2[0][1]))+MM(MM(mat[1][1])*MM(mat2[1][1])));
    
    mat[0][0]=a;
    mat[0][1]=b;
    mat[1][0]=c;
    mat[1][1]=d;
    
}

void power(vvi& mat, int n, vvi base) {
    if(n==1)
        return;
    
    power(mat,n/2,base);
    multiply(mat,mat);
    if(n%2==0) {
        //
    } else {
        multiply(mat,base);
    }
}

int fib(int n) {
    vector<vector<int>> base;
    vector<int> r1={1,1};
    vector<int> r2={1,0};
    base.push_back(r1);
    base.push_back(r2);
    
    power(base,n,base);
    
    return(MM(base[0][1]));
}

void solve() {
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}

int32_t main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
