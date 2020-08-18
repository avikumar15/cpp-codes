#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> vec(n);
    
    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }
    int p;
    cin>>p;
    int k;
    cin>>k;
    
    priority_queue<pair<int,int>> maxh;
    
    for(int i=0;i<n; i++) {
        maxh.push({abs(vec[i]-k),i});
        if(maxh.size()>p)
            maxh.pop();
    }
    stack<pair<int,int>> st;
    while(maxh.size()>0) {
        st.push(maxh.top());
        maxh.pop();
    }
    while(!st.empty()) {
        cout<<st.top().second<<" ";
        st.pop();
    }
    cout<<"\n";
}

int main() {
    int t;
    cin>>t;
    
    while(t--)
        solve();
        
	return 0;
}
