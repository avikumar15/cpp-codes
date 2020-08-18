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

    // maxReached stores max index till which the jump can be made after a particular iteration
    int maxReached=vec[0];
    // steps stores the min number of steps to reach till maxReached.
    int steps=1;
    // flag var to see if maxReached is increasing or not if not, last index can't be reached.
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
