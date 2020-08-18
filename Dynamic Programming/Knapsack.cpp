#include <bits/stdc++.h>
using namespace std;

// weight - [ 10, 20, 30 ]
// value -   [ 60, 100, 120 ]
// W = 50

// T(n)=2^n.

int solveKnapsack(int wt[], int val[], int W, int st, int n, vector<vector<int>>& mmap) {
	// W*n

	for(int i=0; i<=n; i++) {
		mmap[0][i]=0;
	}
	for(int i=0; i<=W; i++) {
		if(i>=wt[0])
			mmap[i][0]=val[0];
		else 
			mmap[i][0]=0;
	}

	for(int i=1; i<=W; i++) {
		// i=4 and j=2
		for(int j=1; j<n; j++) {
			if(i>=wt[j])
				mmap[i][j]=max({mmap[i][j-1],mmap[i-wt[j]][j-1]+val[j]});
			else
				mmap[i][j]=mmap[i][j-1];
		}
	}

	return mmap[W][n-1];
}

int main() {

	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t;
    cin>>t;
    
    while(t--) {
        vector<vector<int>> mmap; 

        int n;
        cin>>n;
        int W;
        cin>>W;
    	
		int wt[n];
    	int val[n];

        for(int i=0; i<n; i++) {
            int f,s;
            cin>>f;
			val[i]=f;
        }
		for(int i=0; i<n; i++) {
            int f,s;
            cin>>f;
			wt[i]=f;
        }

		for(int i=0; i<=W+5; i++) {
			vector<int> temp;
			for(int j=0; j<=n+5; j++) {
				temp.push_back(-1);
			}
			mmap.push_back(temp);
		}
		
		int ans = solveKnapsack(wt,val,W,0,n,mmap);
		
    	cout<<ans<<"\n";

    }
	

}
