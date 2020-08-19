#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void solve() {
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++)
        cin>>vec[i];
        
    int nle[n];
    int ple[n];
    
    // 6 2 5 4 5 1 6
    stack<int> f;
    stack<int> s;
    
    for(int i=0; i<n; i++) {
        
        while(!f.empty() && vec[i]<=vec[f.top()]) {
            f.pop();
        }
        if(f.empty())
            ple[i]=-1;
        else
            ple[i]=f.top();
            
        f.push(i);
    }
    
    // ple - -1 -1 1 1 3 -1 5
    
    // 6 2 5 4 5 1 6
    
    for(int i=n-1; i>=0; i--) {
        
        while(!s.empty() && vec[s.top()]>=vec[i])
            s.pop();
            
        if(s.empty())
            nle[i]=n;
        else 
            nle[i]=s.top();
        
        s.push(i);
    }
    
    // nle - 1 5 3 5 5 7 7
    // ple  -1-1 1 1 3 -1 5
    
    int g[n];
    
    for(int i=0; i<n; i++) {
        g[i]=nle[i]-ple[i]-1;
    }
    
    int mx=0;
    
    for(int i=0; i<n; i++) {
        mx=max(mx,vec[i]*g[i]);   
    }
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
