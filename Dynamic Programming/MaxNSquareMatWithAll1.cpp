    #include<bits/stdc++.h>

    using namespace std;

    int main() {
        int t;
        cin>>t;

        while(t--) {
            int n,m;
            cin>>n;
            cin>>m;

            int G[n+5][m+5];
            int dp[n+5][m+5];

            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    cin>>G[i][j];
                }
            }

            for(int i=0; i<n; i++) {
                dp[i][0]=G[i][0];
            }

            for(int i=0; i<m; i++) {
                dp[0][i]=G[0][i];
            }

            for(int i=1; i<n; i++) {
                for(int j=1; j<m; j++) {
                    if(G[i][j]==0) 
                        dp[i][j]=0;
                    else {
                        if(G[i][j-1]==1 && G[i-1][j]==1 && G[i-1][j-1]==1) {
                            dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                        } else {
                            dp[i][j]=1;
                        }
                    }

                }
            }

            int mx=INT_MIN+50;
            //cout<<endl;
            for(int i=0; i<n; i++) {
                for(int j=0; j<m; j++) {
                    mx=max(mx,dp[i][j]);
            //        cout<<dp[i][j]<<" ";
                }
            //    cout<<endl;
            }

            cout<<mx<<endl;

        }
    }
