#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int vec[n+5];
    int ans[n+5];
    
    for(int i=0; i<n; i++)
        cin>>vec[i];
        
    stack<int> pge;
    
    // 100 80 60 70 60 75 85
    // 1 1 1 2 1 4 6
    
    // 10 4 5 90 120 80
    
    for(int i=0; i<n; i++) {
        while(!pge.empty() && vec[pge.top()]<=vec[i]) {
            pge.pop();
        }
        if(pge.empty())
            ans[i]=i+1;
        else 
            ans[i]=i-pge.top();
            
        pge.push(i);
    }
    
    for(int i=0; i<n; i++) 
        cout<<ans[i]<<" ";
        
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
        solve();
        
	return 0;
}
