#include <bits/stdc++.h>
using namespace std;

int b[20][20];

bool isSafe(int r, int c) {
    
    // cout<<r<<" "<<c<<endl;
    
    // cout<<b[0][0]<<endl;
    
    if(r<0 || c<0 || r>20 || c>20)
        return false;
    
    for(int i=0; i<20; i++) 
        if(b[i][c]==1)
            return false;
            
    for(int i=0; i<20; i++)
        if(b[r][i]==1)
            return false;
        
    int i,j;
    i=r;
    j=c;
    
    while(i>-1 && j>-1 && i<20 && j<20) {
        if(b[i++][j++]==1)
            return false;
    }
    
    i=r;
    j=c;
    
    while(i>-1 && j>-1 && i<20 && j<20) {
        if(b[i--][j++]==1)
            return false;
    }
    
    i=r;
    j=c;
    
    while(i>-1 && j>-1 && i<20 && j<20) {
        if(b[i++][j--]==1)
            return false;
    }
    
    i=r;
    j=c;
    
    while(i>-1 && j>-1 && i<20 && j<20) {
        if(b[i--][j--]==1)
            return false;
    }
    
    return true;
    
}

bool solve(int n, int crnt) {
    
    if(crnt>=n)
        return true;
    
    for(int i=0; i<n; i++) {
        // cout<<"f";
        if(isSafe(i,crnt)) {
            
            b[i][crnt]=1;
            
            if(solve(n,crnt+1))
                return true;
            
            b[i][crnt]=0;
        }
    }
    
    return false;
}

void solve() {
    int n;
    cin>>n;
    
    memset(b,0,sizeof(b));
    
    if(solve(n,0)) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                cout<<b[i][j]<<" ";
            cout<<endl;
        }
    } else {
        cout<<-1<<endl;
    }
}

int main() {
    int t;
    cin>>t;
    
    while(t--) {
        solve();
    }
	return 0;
}
