#include <bits/stdc++.h>
using namespace std;
#define n 9
 
int rows[n+1][n+1];
int cols[n+1][n+1];
int minG[n/3+1][n/3+1][n+1];
 
bool solve(vector<vector<int>>& grid, int i, int j) {
 
    if(i==8 && j==9)
        return true;
 
    if(j==9) {
        j=0;
        i++;
        return solve(grid,i,j);
    }
 
    if(grid[i][j]!=0)
        return solve(grid,i,j+1);
 
    for(int p=1; p<=9; p++) {
        if(rows[i][p]==-1 && cols[j][p]==-1 && minG[i/3][j/3][p]==-1) {
 
            grid[i][j]=p;
 
            rows[i][p]=1;
            cols[j][p]=1;
            minG[i/3][j/3][p]=1;
 
            if(solve(grid,i,j+1))
                return true;
 
            grid[i][j]=0;
            rows[i][p]=-1;
            cols[j][p]=-1;
            minG[i/3][j/3][p]=-1;
        }
 
    }
 
    return false;
 
}
 
void solve() {
 
    vector<vector<int>> grid(9,vector<int>(9,0));
 
    memset(rows,-1,sizeof(rows));
    memset(cols,-1,sizeof(cols));
    memset(minG,-1,sizeof(minG));
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
            if(grid[i][j]!=0) {
                rows[i][grid[i][j]]=1;
                cols[j][grid[i][j]]=1;
                minG[i/3][j/3][grid[i][j]]=1;
            }
        }
    }
 
    if(solve(grid, 0, 0)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    } else {
        cout<<-1<<endl;
    }
}
 
int main() {
 
	int t;
	cin>>t;
 
	while(t--)
	    solve();
 
	return 0;
}
