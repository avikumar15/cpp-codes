#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int len[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};

    int L=8;

    int dp[L+5];
    dp[0]=0;

    for(int i=1; i<=L; i++) {
        dp[i]=price[i-1];
        for(int j=1; j<i; j++) {
            dp[i]=max(dp[i],dp[j]+dp[i-j]);
        }
    }
    
    cout<<dp[L]<<endl;

}
