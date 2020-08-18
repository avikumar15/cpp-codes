#include <bits/stdc++.h>
using namespace std;

int find(string str,int l, int h, map<pair<int,int>,int>& mmap) {
    
    if(l>=h) {
        mmap[{l,h}]=1;
        return 0;
    }
    
    if(str[l]==str[h]){
        int val=find(str,l+1,h-1,mmap);
        mmap[{l,h}]=val;
        return val;
    }
    
    if(mmap.find({l,h})!=mmap.end())
        return mmap[{l,h}];

    int left=find(str,l+1,h,mmap);
    int right=find(str,l,h-1,mmap);
    int val = min(left,right)+1;
    mmap[{l,h}]=val;
    
    return val;
}

void solve() {
    string str;
    cin>>str;
    int n=str.size();
    map<pair<int,int>,int> mmap;
    
    cout<<find(str,0,n-1,mmap)<<"\n";
    
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
