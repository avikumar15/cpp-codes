#include <bits/stdc++.h>
#define mod 1000003
#define int long long

using namespace std;

int fact[20];

int find(string str, int l, int n, map<char,int> mmap) {
    
    if(l==n)
        return 1;
    
    int val = ((mmap[str[l]]%mod)*(fact[n-l-1]%mod))%mod;
    
    for(auto i:mmap) {
        if(i.first==str[l])
            mmap[i.first]=0;
        if(i.first>str[l])
            mmap[i.first]--;
    }
    
    return (val%mod+find(str,l+1,n,mmap)%mod)%mod;
    
}

void solve() {
    string str;//="ABCDEFGH";
    cin>>str;    
    int n = str.size();
        string s2=str;
        sort(s2.begin(),s2.end());
        
        
        map<char,int> mmap;
        
        for(int i=0; i<n; i++) {
            mmap[s2[i]]=i;
        }
        
        int ans = find(str, 0, n, mmap);
        cout<<(ans)%mod<<endl;
    }

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fact[0]=1;
    for(int i=1; i<20; i++){
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
    
    int t;
    cin>>t;
    
    while(t--)
        solve();
        
	return 0;
}
