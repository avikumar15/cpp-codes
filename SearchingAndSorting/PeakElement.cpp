// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* The function should return the index of any
   peak element present in the array */

// arr: input array
// n: size of array
int peakElement(int arr[], int n)
{
    // 10, 20, 15, 2, 23, 90, 67
    // 20 or 90
    
    int l=0;
    int h=n-1;
    int mid=l+(h-l)/2;
    int ans=-1;
    
    while(h>=l) {
        mid=l+(h-l)/2;
        
        if(mid==0) {
            if(arr[mid+1]<=arr[mid]) {
                ans=mid;
                break;
            }
        } else if(mid==n-1) {
            if(arr[mid]>=arr[mid-1]) {
                ans=mid;
                break;
            }
        } else {
            if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) {
                ans=mid;
                break;
            }
        }
        
        if(arr[mid]<arr[mid-1]) {
            h=mid-1;
        } else {
            l=mid+1;
        }
        
    }
    
    return ans;
    
   // Your code here
}

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		bool f=0;
		int A = peakElement(a,n);
		
		if(n==1)
		f=1;
		else
		if(A==0 and a[0]>=a[1])
		f=1;
		else if(A==n-1 and a[n-1]>=a[n-2])
		f=1;
		else if(a[A] >=a[A+1] and a[A]>= a[A-1])
		f=1;
		else
		f=0;
		
		cout<<f<<endl;
		
	}

	return 0;
}  // } Driver Code Ends