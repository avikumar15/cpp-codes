#include<bits/stdc++.h>

using namespace std;

// 1 D method
int count( int S[], int m, int n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is constructed 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 

void solve() {
    int n,m;
    vector<int> vec;

    cin>>m;

    for(int i=0; i<m; i++) {
        int temp;
        cin>>temp;
        vec.push_back(temp);
    }

    cin>>n;

    int dp[n+5][m+5];

    for(int i=0; i<m; i++) {
        dp[0][i]=1;
    }

    for(int i=1; i<=n; i++) {
        if(i%vec[0]==0)
            dp[i][0]=1;
        else 
            dp[i][0]=0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<m; j++) {
            if(i<vec[j]) {
                dp[i][j]=dp[i][j-1];
            } else {
                // either to add a current coin with current row col current -vec[j]
                // or simply last column.
                dp[i][j]=dp[i][j-1]+dp[i-vec[j]][j];
            }
        }
    }

    cout<<dp[n][m-1]<<endl;

}

int main() {
    int t;
    cin>>t;

    while(t--) {
        solve();
    }

    return 0;
}
