#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

void solve(int a, int b, int c) {
    float r1=1;
    float r2=2;
    if(a!=0 && b!=0) {
        r1 = float(b)/float(a);
        r2 = float(c)/float(b);
    }

    int diff = c-b;

    if(r1==r2) {
        cout<<"GP ";
        cout<<c*r1<<endl;
    } else {
        cout<<"AP ";
        cout<<c+diff<<endl;
    }
}

int32_t main() {
    fastio;

    int a;
    int b;
    int c;

    while(1) {

        cin>>a>>b>>c;

        if(a==0 && b==0 && c==0)
        break;

        solve(a,b,c);
    }
    return 0;
}