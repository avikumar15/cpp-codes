/**
 * This code belongs to Avi (106118017)
*/
#include <bits/stdc++.h>
#define int long long

using namespace std;

int32_t main() {

    int t=1;
    cin>>t;

    while(t--) {
        string s1,s2;

        cin>>s1>>s2;

        int dp[s2.size()+5][s1.size()+5];

        // to make s2 till length i from empty s1, we will need i addition operations
        for(int i=0; i<s2.size()+5; i++) {
            dp[i][0]=i;
        }

        // to make empty s2 from s1 of length i, we will need i deletion operations
        for(int i=0; i<s1.size()+5; i++) {
            dp[0][i]=i;
        }

        for(int i=1; i<s2.size()+1; i++) {
            for(int j=1; j<=s1.size(); j++) {
                // if the letter is equal then simply dp[i][j]=dp[i-1][j-1]
                if(s1[j-1]==s2[i-1]) {
                    dp[i][j]=dp[i-1][j-1];
                } else {
                    // if the letter is not equal then dp[i][j]=min of neighbouring dp value + 1
                    dp[i][j]=min({dp[i-1][j-1]+1,dp[i][j-1]+1,dp[i-1][j]+1});
                }
            }
        }

        cout<<dp[s2.size()][s1.size()]<<endl;

    }

    return 0;
}
