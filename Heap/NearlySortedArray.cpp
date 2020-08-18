#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> a(n);
    
    priority_queue<int, vector<int>, greater<int>> minh;
    vector<int> res;
    
    for(int i=0; i<n; i++)
        cin>>a[i];
        
    for(int i=0; i<k; i++) 
        minh.push(a[i]);
        
    for(int i=k; i<n; i++) {
        res.push_back(minh.top());
        minh.pop();
        minh.push(a[i]);
    }
    
    while(!minh.empty()) {
        res.push_back(minh.top());
        minh.pop();
    }
    
    for(int i=0; i<n; i++) {
        cout<<res[i]<<" ";
    }
    cout<<"\n";
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
