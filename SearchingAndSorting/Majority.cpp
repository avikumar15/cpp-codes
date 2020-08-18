#include <iostream>
using namespace std;
#include<bits/stdc++.h>

void solve() {
    int n;
    cin>>n;
    int temp;
    vector<int> vec;
    
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);    
    }
    
    int x;
    cin>>x;
    
    if(binary_search(vec.begin(),vec.end(),x)) {
        int lb=lower_bound(vec.begin(),vec.end(),x)-vec.begin();
        int ub=upper_bound(vec.begin(),vec.end(),x)-vec.begin();
        if(ub-lb>=ceil(n/2.0))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
    } else {
        cout<<-1<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
