#include<bits/stdc++.h>

using namespace std;

bool isValid(int i, int j, int n, int m) {
    if(i<0 || j<0 || i>=n || j>=m)
        return false;
    return true;
}

int main() {
    int n=4,m=5;

    int grid[n][m]={{0, 1, 1, 0, 1}, 
                    {0, 1, 0, 1, 0}, 
                    {0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0}};

    queue<pair<int,pair<int,int>>> q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]==1)
                q.push({0,{i,j}});
        }
    }

    int lvl=0;

    while(!q.empty()) {
        
        pair<int,pair<int,int>> f=q.front();
        
        int i=f.second.first;
        int j=f.second.second;
        int cnt=f.first;

        q.pop();

        if(isValid(i-1,j,n,m) && grid[i-1][j]==0) {
            grid[i-1][j]=1;
            q.push({cnt+1,{i-1,j}});
            lvl=cnt+1;
        } 
        if(isValid(i+1,j,n,m) && grid[i+1][j]==0) {
            grid[i+1][j]=1;
            q.push({cnt+1,{i+1,j}});
            lvl=cnt+1;
        }
        if(isValid(i,j+1,n,m) && grid[i][j+1]==0) {
            grid[i][j+1]=1;
            q.push({cnt+1,{i,j+1}});
            lvl=cnt+1;
        }
        if(isValid(i,j-1,n,m) && grid[i][j-1]==0) {
            grid[i][j-1]=1;
            q.push({cnt+1,{i,j-1}});
            lvl=cnt+1;
        }

    }

    cout<<lvl<<endl;

}
