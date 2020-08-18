#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int temp;
    vector<int> vec;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
    int s=vec[0];
    for(int i=1; i<n; i++) {
        s^=vec[i];
    }
    cout<<s<<endl;
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
