// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int s){
    
    // 5 12
    // 1 (2 3 7) 5
    
    // 10 15
    // 12 1 7 3 4 5 6 7 8 9 10
    
    long long p1=0,p2=0;
    long long sum=0;
    
    for(int i=0; i<n; i++) {
        sum+=arr[i];
        p2++;
        while(sum>s) {
            sum-=arr[p1++];
        }
        if(sum==s) {
            break;
        }
    }
    
    if(sum==s) {
        cout<<p1+1<<" "<<p2;
    } else {
        cout<<-1;
    }
    
}

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends