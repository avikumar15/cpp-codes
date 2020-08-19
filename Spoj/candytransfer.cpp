#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 

using namespace std;

int solve(int a, vector<int> candies, int sum) {
    int p=sum/a;
    if(sum%a!=0) {
        return -1;
    } else {
        sort(candies.begin(),candies.end());
        int count = 0;
    //    cout<<"p is "<<p<<endl;
        for(int i=0; i<candies.size(); i++) {
            if(candies[i]>p) {
                count+=candies[i]-p;
    //            cout<<"count incremented to "<<count<<" at "<<candies[i]<<endl;
            }
        }
        return count;
    }
}

int32_t main() {
    fastio;

    int a;
    int b;

    while(1) {
        cin>>a;
        
        vector<int> candies;

        if(a==-1)
        break;

        int sum=0;

        for(int i=0; i<a; i++) {
            cin>>b;
            sum+=b;
            candies.push_back(b);
        }

        cout<<solve(a,candies,sum)<<endl;
    }
    return 0;
}