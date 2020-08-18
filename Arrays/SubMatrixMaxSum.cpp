#include<bits/stdc++.h>

using namespace std;

int main() {
    
    int n=4;

    int mat[4][4] = { {1,2,-1,4}, {-8,-3,4,2}, {3,8,10,-8}, {-4,-1,1,7} };

    int sum[4][4];

    sum[0][0]=mat[0][0];

    for(int i=1; i<n; i++) {
        sum[0][i]=sum[0][i-1]+mat[0][i];
    }

    for(int i=1; i<n; i++) {
        sum[i][0]=sum[i-1][0]+mat[i][0];
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<n; j++) {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    int k=1;
    int ans=INT_MIN;
    for(;k<n; k++) {
        for(int i=k-1; i<n; i++) {
            for(int j=k-1; j<n; j++) {
                
                int temp = sum[i][j];
                
                if(i>=k && j>=k) {
                    temp-=sum[i-k][j];
                    temp-=sum[i][j-k];
                    temp+=sum[i-k][j-k];
                } else if(i>=k) {
                    temp-=sum[i-k][j];
                } else if(j>=k) {
                    temp-=sum[i][j-k];
                }

                ans=max(ans,temp);
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
