#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void solve() {
    int n;
    int t;
    vector<int> vec;
    cin>>n;
    int k;
    cin>>k;
    
    for(int i=0; i<n; i++) {
        cin>>t; 
        vec.push_back(t);
    }
    
    sort(vec.begin(),vec.end());
    
    int p1=n-1;
    int p2=0;
    int flag=0;
    
    while(p1>p2) {
        if(vec[p1]+vec[p2]==k) {
            flag=1; 
            break;
        }
        else if((vec[p1]+vec[p2])>k)
            p1--;
        else
            p2++;
    }
    
    if(flag==1)
        cout<<"Yes\n";
    else 
        cout<<"No\n";
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
