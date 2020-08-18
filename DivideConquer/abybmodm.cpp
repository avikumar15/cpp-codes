#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

int findMod(int a) {
    return a%mod;
}

int power(int a, int b) {
    if(a==1 || b==0)
        return 1;
    int val=findMod(power(a,b));
    if(b%2==0) {
        return findMod(val*val);
    } else {
        return findMod(findMod(val*val)*findMod(a));
    }
}

int abyb(int a, int b) {
    return findMod(findMod(a)*findMod(power(b,mod-2)));
}

int main() {
    int a,b;
    cin>>a>>b;

    cout<<abyb(a,b)<<endl;
}
