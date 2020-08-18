#include<bits/stdc++.h>

using namespace std;

const int N=4;
const int M=4;

char grid[N][M] = { { '0', '*', '0', 's' }, 
                    { '*', '0', '*', '*' }, 
                    { '0', '*', '*', '*' }, 
                    { 'd', '*', '*', '*' } }; 


int cost[5][5] = { 
        31, 100, 65, 12, 18, 
        10, 13, 47, 157, 6, 
        100, 113, 174, 11, 33, 
        88, 124, 41, 20, 140, 
        99, 32, 111, 41, 20 
    }; 

int dp[1000][1000];

int dfs2(vector<vector<bool>> isVisited, int si, int sj, int r, int c) {
    
    if(si<0 || sj<0 || si>r-1 || sj>c-1) {
        return INT_MAX/10;
    }

    // cout<<si<<" "<<sj<<endl;

    if(isVisited[si][sj]) {
        return INT_MAX/10;
    }

    isVisited[si][sj]=true;

    if(si==r-1 && sj==c-1)
        return cost[si][sj];

    // if(dp[si][sj]!=-1)
    //     return dp[si][sj];

    int a = cost[si][sj]+dfs2(isVisited,si+1,sj,r,c);
    int b = cost[si][sj]+dfs2(isVisited,si,sj+1,r,c);
    int f = cost[si][sj]+dfs2(isVisited,si-1,sj,r,c);
    int d = cost[si][sj]+dfs2(isVisited,si,sj-1,r,c);

    if(si+1<r)
        dp[si+1][sj]=a;
    if(sj+1<c)
        dp[si][sj+1]=b;
    if(si-1>=0)
        dp[si-1][sj]=c;
    if(sj-1>=0)
        dp[si][sj-1]=d;

    return dp[si][sj]=min({a,b,f,d});

}

int main() {
    
    int n=N;
    int m=M;

    vector<vector<bool>> isVisited;
    
    int si,sj;
    int di,dj;

    for(int i=0; i<5; i++) {
        vector<bool> temp;
        for(int j=0; j<5; j++) {
            temp.push_back(false);
        }
        isVisited.push_back(temp);
    }
    
    int ans=0;

    memset(dp,-1,sizeof(dp));
    
    ans=dfs2(isVisited, 0, 0, 5, 5);

    cout<<ans<<endl;

}
