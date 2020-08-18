#include <iostream>
using namespace std;
#include<bits/stdc++.h>
void solve() {
    int n;
    cin>>n;
    int t;
    vector<int> vec;
    vector<int> pos;
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
    for(int i=0; i<n; i++)
        if(vec[i]>0)
            pos.push_back(vec[i]);
    n=pos.size();
    int mx=INT_MIN+50;
    for(int i=0; i<n; i++) {
        mx=max(mx,abs(pos[i]));
        int ab=abs(pos[i]);
        if(ab-1<0 || ab-1>n-1)
            continue;
        pos[ab-1]=-1*abs(pos[ab-1]);
    }
    int ans=mx;
    for(int i=0; i<n; i++) {
        if(pos[i]>0) {
            ans=i;
            break;
        }
    }
    cout<< ans+1<<endl;
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
