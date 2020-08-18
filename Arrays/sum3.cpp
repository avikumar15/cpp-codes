#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--) {
        
        int n;
        int t;
        vector<int> vec;
        cin>>n;
        int x;
        cin>>x;
        for(int i=0; i<n; i++){
            cin>>t; 
            vec.push_back(t);
        }
        sort(vec.begin(),vec.end());
        
        int ans=0;
        
        for(int i=0; i<n; i++) {
            int p1=i+1;
            int p2=n-1;
            while(p2>p1) {
                
                if(vec[i]+vec[p1]+vec[p2]==x) {
                    ans=1;
                    break;
                }
                if(vec[i]+vec[p1]+vec[p2]>x) {
                    p2--;
                } else {
                    p1++;
                }
            }
            if(ans==1)
                break;
        }
        
        cout<<ans<<endl;
    }
	return 0;
}