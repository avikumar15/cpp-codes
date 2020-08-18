#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n,m;
    vector<int> a,b,res;
    cin>>n>>m;
    
    int temp;
    for(int i=0; i<n; i++) {
        cin>>temp;
        a.push_back(temp);
    }
    
    for(int i=0; i<m; i++) {
        cin>>temp;
        b.push_back(temp);
    }
    
    int s1=0,s2=0;

    // {1, 3, 4, 5, 7}
    // {2, 3, 5, 6} 

    while(s1<n && s2<m) {
        if(a[s1]<b[s2]) {
            if(res.size()==0 || res[res.size()-1]!=a[s1])
            res.push_back(a[s1]);
            s1++;
        } else if(a[s1]>b[s2]) {
            if(res.size()==0 || res[res.size()-1]!=b[s2])
            res.push_back(b[s2]);
            s2++;
        } else {
            if(res.size()==0 || res[res.size()-1]!=a[s1])
            res.push_back(a[s1]);
            s2++;
            s1++;
        }
    }

    while(s1<n) {
        if(res.size()==0 || res[res.size()-1]!=a[s1])
        res.push_back(a[s1]);
        s1++;
    }
    while(s2<m) {
        if(res.size()==0 || res[res.size()-1]!=b[s2])
        res.push_back(b[s2]);
        s2++;
    }

    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
