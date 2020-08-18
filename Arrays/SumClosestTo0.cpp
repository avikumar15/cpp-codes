#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    
    vector<int> vec(n);
    
    for(int i=0; i<n; i++) {
        cin>>vec[i];
    }
    
    sort(vec.begin(),vec.end());
    
    // -67 -65 -37 -21 -18 4
    int p1=0;
    int p2=n-1;
    int ans=INT_MAX;
    int val=-1;
    
    while(p2>p1) {
        if(abs(vec[p2]+vec[p1])<ans)
            val=vec[p2]+vec[p1];
        ans=min(ans,abs(vec[p2]+vec[p1]));
        if(vec[p1]+vec[p2]<0)
            p1++;
        else if(vec[p1]+vec[p2]>0)
            p2--;
        else 
            break;
    }
    
    cout<<val<<endl;
    
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
