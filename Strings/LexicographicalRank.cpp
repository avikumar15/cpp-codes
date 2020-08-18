#include <bits/stdc++.h>
#define mod 1000003
#define int long long

using namespace std;

void factorial(int fact[], int n) {
    fact[0]=1;
    for(int i=1; i<=n; i++) {
        fact[i]=((fact[i-1]%mod)*(i%mod))%mod;
    }
}

int find(string str, map<char,int> p,int fact[], int n) {
    
    int res=0;
    for(int i=0; i<n; i++) {
        
        res+=(((fact[n-i-1])%mod) * ((p[str[i]])%mod))%mod;
        res=res%mod;
        for(auto mmp:p) {
            
            if(mmp.first==str[i]){
                p[mmp.first]=0;
            }
            if(mmp.first>str[i])
                p[mmp.first]--;
        }
    }
    return (res+1)%mod;
}

void solve() {
    int n;
    string str;
    cin>>str;
    n=str.size();
    string str2=str;
    sort(str2.begin(),str2.end());
    map<char,int> p;
    
    int cnt=0;
    int flag=1;
    
    for(int i=0; i<n; i++) {
        p[str2[i]]=cnt++;
        if(i!=0)
        if(str2[i]==str2[i-1])
            flag=-1;
    }
    
    if(flag==-1) {
        cout<<0<<endl;
        return;
    }
    
    int fact[20];
    factorial(fact,18);
    
    int ans = find(str,p,fact,n);
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--)
        solve();
        
	return 0;
}
