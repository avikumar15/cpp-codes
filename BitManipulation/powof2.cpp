#include<bits/stdc++.h>

using namespace std;

int main() {
    int N=5;

    if(N&&!(N&(N-1))) {
        cout<<"Yes\n";
    } else {
        cout<< (N&(N-1)) <<" No\n";
    }
    
}