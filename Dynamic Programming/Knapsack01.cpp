#include <bits/stdc++.h>
using namespace std;

// weight - [ 10, 20, 30 ]
// value -   [ 60, 100, 120 ]
// W = 50

// ALTERNATE.
int solveKnapsack(int wt[], int val[], int n, int W, vector<vector<int>>& dp) {
    if(W==0 || n==0)
        return 0;
    if(dp[W][n]!=-1)
        return dp[W][n];
    if(W<wt[n-1])
        return dp[W][n]=solveKnapsack(wt,val,n-1,W,dp);
    return (dp[W][n]=max(val[n-1]+solveKnapsack(wt,val,n-1,W-wt[n-1],dp), solveKnapsack(wt,val,n-1,W,dp)));
}

int main() {

	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--) {

        int n;
        cin>>n;
        int W;
        cin>>W;
    	
		int wt[n];
    	int val[n];

        for(int i=0; i<n; i++)
            cin>>val[i];
        for(int i=0; i<n; i++)
            cin>>wt[i];
        
        vector<vector<int>> dp (W+1, vector<int> (n+1,-1)); 
            
        //int ans=solveKnapsack(wt,val,n,W,dp);
        
        for(int i=0; i<n+1; i++)
            dp[0][i]=0;
        
        for(int i=0; i<W+1; i++)
            dp[i][0]=0;
        
        for(int i=1; i<W+1; i++) {
            for(int j=1; j<n+1; j++) {
                if(wt[j-1]>i) {
                    dp[i][j]=dp[i][j-1];
                } else {
                    dp[i][j]=max(dp[i][j-1],dp[i-wt[j-1]][j-1]+val[j-1]);
                }
            }
        }
        
        cout<<dp[W][n]<<endl;

    }
	

}
