#include <bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>

void solve() {
    int n;
    vector<int> vec;
    int t;
    int k;
    
    cin>>n;
    cin>>k;
    
    for(int i=0; i<n; i++)
        cin>>t, vec.push_back(t);
    
    deque<int> q;
    
    // 1 2 3 1 4 5 2 3 6
    // 3
    q.push_back(0);
    
    // 0
    // 1
    // 2
    // 5 3 2 1 4
    for(int i=1; i<k; i++) {
        
        while(!q.empty() && vec[q.back()]<=vec[i]) {
            q.pop_back();    
        }
        
        q.push_back(i);
    }
    
    vector<int> res;
    
    for(int i=k; i<n; i++) {
        res.push_back(vec[q.front()]);
        
        while(!q.empty() && q.front()<i-k+1) {
            q.pop_front();
        }
        
        while(!q.empty() && vec[q.back()]<=vec[i])
            q.pop_back();
        
        q.push_back(i);
    }
    
    res.push_back(vec[q.front()]);
    
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";
        
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
