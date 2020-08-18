#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        int n;
        cin>>n;
        vector<int> vec;
        int t;
        
        for(int i=0; i<n; i++) 
            cin>>t, vec.push_back(t);
            
        map<int,int> mmap;
        mmap[0]=1;
        int curr=0;
        string ans="No\n";
        
        for(int i=0; i<n; i++) {
            curr+=vec[i];
            if(mmap.find(curr)!=mmap.end()) {
                ans="Yes\n";
                break;
            }
            mmap[curr]=1;
        }
        
        cout<<ans;
    }
    
	return 0;
}
