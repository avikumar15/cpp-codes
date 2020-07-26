// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    vector<int> mmap(1000005,0);
    int mx=INT_MIN+50;
    
    for(int i=0; i<n; i++) {
        mmap[arr1[i]]=1;
        mx=max(mx,arr1[i]);
    }
    
    for(int i=0; i<m; i++) {
        mmap[arr2[i]]=1;
        mx=max(mx,arr2[i]);
    }
    
    vector<int> ans;
    
    for(int i=0; i<=mx; i++) {
        if(mmap[i]==1) {
            ans.push_back(i);
        } 
    }
    
    
    return ans;
    
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    vector<int> ans = findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends