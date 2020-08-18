#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void solve() {
    int n;
    int t;
    vector<int> vec;
    cin>>n;
    n*=2;
    n+=2;
    int x=0;
    for(int i=0; i<n; i++) {
        cin>>t;
        vec.push_back(t);
        x^=vec[i];
    }
    // cout<<"debug x "<<x<<endl;
    int num = x&(~(x-1));
    // cout<<"debug num "<<num<<endl;
    int a1=0,a2=0;
    
    for(int i=0; i<n; i++) {
        if(num&vec[i])
            a1^=vec[i];
        else 
            a2^=vec[i];
    }
    
    cout<<min(a2,a1)<<" "<<max(a1,a2)<<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
