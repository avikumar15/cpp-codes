// Only for distinct elments.

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    vector<int> vec;
    cin>>n;
    int temp;
    
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
    
    int l=0;
    int h=n-1;
    int m;
    int ans=-1;
    
    while(h>l+1) {
        m=l+(h-l)/2;
        
        if(vec[m]==m) {
            ans=m;
            break;
        } else if(vec[m]<m) {
            l=m;
        } else {
            h=m;
        }
        
    }
    
    for(int i=l-2; i<=l+2; i++) {
        if(i<0 || i>=n)
            continue;
        if(vec[i]==i) {
            ans=i;
            break;
        }
    }
    
    cout<< ans <<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
