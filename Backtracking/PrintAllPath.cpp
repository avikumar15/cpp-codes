#include<bits/stdc++.h>

using namespace std;

int mat[100][100];

// vector<vector<int>> res;

void solve(int i, int j, int n, int m, vector<int> f) {

    if(i<0 || j<0 || i>n-1 || j>m-1)
        return;

    f.push_back(mat[i][j]);

    if(i==n-1 && j==m-1) {
        for(int p=0; p<f.size(); p++)
            cout<<f[p]<<" ";
        cout<<endl;
        return;
    }

    solve(i+1,j,n,m,f);
    solve(i,j+1,n,m,f);

}

int main() {
    memset(mat,-1,sizeof(mat));

    int n=2,m=3;

    mat[0][0]=1;
    mat[0][1]=2;
    mat[0][2]=3;

    mat[1][0]=4;
    mat[1][1]=5;
    mat[1][2]=6;

    vector<int> f;
    
    solve(0,0,n,m,f);

    // for(int i=0; i<res.size(); i++) {
    //     for(int j=0; j<)
    // }

}
