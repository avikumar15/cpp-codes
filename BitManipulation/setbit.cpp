#include<bits/stdc++.h>

using namespace std;

void printBinary(int N) {
    
    int p = floorf(log2(N));
    
    cout<<"p is "<<p<<endl;

    p=pow(2,p);

    cout<<"p is "<<p<<endl;

    while(p>0) {
        cout<<(N&p)/p;
        p/=2;
    }
    cout<<endl;
}

int setbitCount(int N) {

    if(N==0) {
        return 0;
    }
    return 1+setbitCount(N&(N-1));
}

int main() {

    int N = 29;

    printBinary(N);

    cout<<"Number of set bits - "<<setbitCount(N);

    return 0;
}