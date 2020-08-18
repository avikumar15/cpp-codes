#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
        
    priority_queue<int,vector<int>,greater<int>> minh;
    
    for(int i=0; i<n; i++) {
        minh.push(vec[i]);
        if(minh.size()>k)
            minh.pop();
    }
    
    stack<int> st;
    while(!minh.empty()) {
        st.push(minh.top());
        minh.pop();
    }
    
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
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
