#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n,temp;
    cin>>n;
    vector<int> vec;

    for(int i=0; i<n; i++) {
        cin>>temp;
        vec.push_back(temp);
    }

    int dp[n+5];
    dp[0]=0;
    int maxReached=vec[0];
    int steps=1;
    int fu=1;

    for(int i=1; i<n; i++) {
        int j=i;
        int mx=maxReached;
        if(maxReached>=n-1) {
            break;
        }
        while(j<=maxReached && j<n) {
            mx=max(mx,vec[j]+j);
            j++;
        }
        if(mx>maxReached) {
            steps++;
            maxReached=mx;
        } else {
            fu=-1;
            break;
        }
    }

    if(fu==-1) {
        cout<<-1<<endl;
    } else {
        cout<<steps<<endl;
    }

}

int main() {
    int t;
    cin>>t;

    while(t--)
        solve();

}
