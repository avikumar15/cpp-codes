#include <bits/stdc++.h>
using namespace std;

void populate(vector<string>& ans, string str, int l, int r) {
    
    if(l==r)
        ans.push_back(str);
    
    for(int i=l; i<=r; i++) {
        swap(str[i],str[l]);
        populate(ans,str,l+1,r);
        swap(str[i],str[l]);
    }
}

void solve() {
    
    string str;
    cin>>str;
    sort(str.begin(),str.end());
    int n=str.size();
    
    vector<string> ans;
    populate(ans,str,0,n-1);
    
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
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
