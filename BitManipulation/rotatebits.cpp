#include<bits/stdc++.h>

using namespace std;

void printBinary(int N) {
    
    int p = floorf(log2(N));
    
//    cout<<"p is "<<p<<endl;

    p=pow(2,p);

//    cout<<"p is "<<p<<endl;

    while(p>0) {
        cout<<(N&p)/p;
        p/=2;
    }
    cout<<endl;
}

int rotateLeft(int N, int by) {
    int p = pow(2,floor(log2(N)));

    while(by) {
        
        int t = (p&N)/p;
    //    cout<<"t is "<<t<<" and N is "<<N<<" p is "<<p<<endl;

        N<<=1;
        
    //    cout<<"N is "<<N<<endl;

        N|=t;
        N&=(p*2-1);

    //    printBinary(N);

        by--;
    }
    return N;
}

int main() {

    int N = 29;

    printBinary(N);

    int rotateL3 = rotateLeft(N,3); 

    cout<<rotateL3<<endl;
    printBinary(rotateL3);

    return 0;
}