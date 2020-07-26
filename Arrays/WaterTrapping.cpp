// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


   

// function to find the trapped water in between buildings
// arr: input array
// n: size of array
int trappingWater(int arr[], int n){

    // Your code here
    if(n==0) {
        return 0;
    }
    
    int mx=arr[0];
    int mxleft[n];
    int mxright[n];
    long long ans=0;
    
    mxleft[0]=arr[0];
    mxright[n-1]=arr[n-1];
    
    for(int i=1; i<n; i++) {
        mxleft[i]=max(mxleft[i-1],arr[i]);
    }
    
    for(int i=n-2; i>=0; i--) {
        mxright[i]=max(arr[i],mxright[i+1]); 
    }
    
    for(int i=1; i<n-1; i++) {
        ans+=min(mxleft[i],mxright[i])-arr[i];
    }
    
    return ans;
}

// { Driver Code Starts.

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        
        int a[n];
        
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        
        cout << trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends