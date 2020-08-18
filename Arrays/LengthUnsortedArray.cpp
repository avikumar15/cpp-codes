#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    vector<int> vec;
    int temp;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
    
    vector<int> sec;
    int s=0,e=n-1;
    
    for(int i=1; i<n; i++) {
        if(vec[i]<vec[i-1]) {
            s=i-1;
            break;
        }
    }
    
    for(int i=n-2; i>=0; i--) {
        if(vec[i]>vec[i+1]) {
            e=i+1;
            break;
        }
    }
    
    int mx=INT_MIN+50;
    int mn=INT_MAX-50;
    
    for(int i=s; i<=e; i++) {
        mx=max(mx,vec[i]);
        mn=min(mn,vec[i]);
    }
    
    for(int i=0; i<s; i++) {
        if(vec[i]>mn) { 
            s=i;
            break;
        }
    }
    
    for(int i=e+1; i<n; i++) {
        if(vec[i]<mx) { 
            e=i;
        }
    }
    
    cout<<s<<" "<<e<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
