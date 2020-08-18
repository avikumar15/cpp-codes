#include<bits/stdc++.h>

using namespace std;

const int N=4;
const int M=4;

char grid[N][M] = { { '0', '*', '0', 's' }, 
                    { '*', '0', '*', '*' }, 
                    { '0', '*', '*', '*' }, 
                    { 'd', '*', '*', '*' } }; 

int dp[1000][1000];

int dfs(char grid[4][4], vector<vector<bool>> isVisited, int si, int sj, int r, int c) {
    
    if(si<0 || sj<0 || si>r-1 || sj>c-1) {
        return INT_MAX/10;
    }

    if(isVisited[si][sj]) {
        return INT_MAX/10;
    }

    isVisited[si][sj]=true;

    if(grid[si][sj]=='d')
        return 1;

    int a = 1+dfs(grid,isVisited,si+1,sj,r,c);
    int b = 1+dfs(grid,isVisited,si,sj+1,r,c);
    int f = 1+dfs(grid,isVisited,si-1,sj,r,c);
    int d = 1+dfs(grid,isVisited,si,sj-1,r,c);

    return min({a,b,f,d});

}

int main() {
    
    int n=N;
    int m=M;

    vector<vector<bool>> isVisited;
    
    int si,sj;
    int di,dj;

    for(int i=0; i<n; i++) {
        vector<bool> temp;
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='s') {
                si=i;
                sj=j;
            }
            if(grid[i][j]=='d') {
                di=i;
                dj=j;
            }
            if(grid[i][j]=='0') {
//                isVisited[i][j]=true;
                temp.push_back(true);
            } else {
                // isVisited[i][j]=false;
                temp.push_back(false);
            }
        }
        isVisited.push_back(temp);
    }
    
    int ans=0;

    ans=dfs(grid, isVisited, si, sj, n, m);

    cout<<ans-1<<endl;

}
