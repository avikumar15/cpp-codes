#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int t;
    vector<int> vec;
    
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
        
    int inc[n+5],dec[n+5];
    inc[0]=1;
    dec[n-1]=1;
    int cnt=1;
    // 12 4 78 90 45 23
    for(int i=1; i<n; i++) {
        if(vec[i]>vec[i-1]) {
            cnt++;        
        } else {
            cnt=1;
        }
        inc[i]=cnt;
    }
    cnt=1;
    for(int i=n-2; i>=0; i--) {
        if(vec[i]>vec[i+1]) {
            cnt++;        
        } else {
            cnt=1;
        }
        dec[i]=cnt;
    }
    
    int mx=INT_MIN+50;
    
    for(int i=0; i<n; i++)
        mx=max(mx,inc[i]+dec[i]-1);
        
    cout<<mx<<endl;
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
