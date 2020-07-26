#include<bits/stdc++.h>
#define int long long

using namespace std;

int gcd(int x, int y) {
    
    int mx=max(x,y);
    int mn=min(x,y);

    if(mn==0)
        return mx;

    return gcd(mx%mn,mn);

}

int32_t main() {
    int x,y;
    cin>>x>>y;
    cout<<"GCD of "<<x<<" and "<<y<<" is "<<gcd(x,y)<<endl;
}
