#include<bits/stdc++.h>
#define int long long

using namespace std;

int ncr(int n, int r) {

    // p is for numerator and k for denominator.
    int p=1,k=1;

    // ncr = nc(n-r).
    r=min(r,n-r);

    // when r is 0, ncr is 1.
    if(r==0) {
        return 1;
    }

    while(r>0) {

        // numerator * n * (n-1) ... like that
        p*=n;
        // denominator like r * (r-1) ... like that
        k*=r;

        // dividing both numerator and denominator by gcd of num and denominator.
        int g=__gcd(p,k);

        p/=g;
        k/=g;

        // making n as n-1 and r as r-1.
        n--;
        r--;

    }

    return p;

}

int32_t main() {

    int n=50;
    int r=25;

    int ans = ncr(50,25);

    cout<<ans<<endl;

}
