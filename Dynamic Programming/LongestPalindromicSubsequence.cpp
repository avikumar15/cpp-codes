#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str="";
    cin>>str;

    int n=str.size();

    int dp[n+5][n+5];

    for(int i=0; i<n; i++)
        dp[i][i]=1;
    
    for(int i=0; i<n-1; i++)
        if(str[i]==str[i+1])
            dp[i][i+1]=2;
        else
            dp[i][i+1]=1;
    
    for(int i=2; i<n; i++) {
        int c=i;
        for(int j=0; j<n-c; j++) {
            if(str[i]==str[j]) {
                dp[j][i]=dp[j+1][i-1]+2;
            } else {
                dp[j][i]=max(dp[j+1][i],dp[j][i-1]);
            }
            i++;
        }
        i=c;
    }

    cout<<dp[0][n-1]<<endl;

    return 0;
}
