#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>

using namespace std;

int32_t main() {
    vi vec;
    int n;
    int temp;

    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }
    int x;
    cin>>x;

    int left = lower_bound(vec.begin(),vec.end(),x)-vec.begin();
    int right = upper_bound(vec.begin(),vec.end(),x)-vec.begin();

    cout<<right-left<<endl; 

}
