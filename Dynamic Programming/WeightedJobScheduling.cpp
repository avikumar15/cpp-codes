#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int solveKnap(vector<pair<int,pair<int,int>>> vec, int n, int startTime) {
    if(n==0)
        return 0;

    if(dp[n][startTime]!=-1)
        return dp[n][startTime];

    if(vec[n-1].first>startTime) {
        return dp[n][startTime]=solveKnap(vec,n-1,startTime);
    }

    return dp[n][startTime]=max(solveKnap(vec,n-1,startTime),solveKnap(vec,n-1,vec[n-1].second.first)+vec[n-1].second.second);
}

int main() {
    
    vector<pair<int,pair<int,int>>> vec;
    
    vec.push_back({2,{1,50}});
    vec.push_back({5,{3,20}});
    vec.push_back({19,{6,100}});
    vec.push_back({100,{2,200}});

    memset(dp,-1,sizeof(dp));

    sort(vec.begin(),vec.end());

    int n=vec.size();
    
    int ans=solveKnap(vec,n,INT_MAX);
    cout<<ans<<endl;

}
