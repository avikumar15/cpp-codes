// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int arr[], int n);

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << maxLen(a, n) << endl;
    }
    return 0;
}// } Driver Code Ends


/*You are required to complete this method*/

// arr[] : the input array containing 0s and 1s
// N : size of the input array

// return the maximum length of the subarray
// with equal 0s and 1s
int maxLen(int arr[], int N)
{
    int n=N;
    map<int,vector<int>> pval;
    int sum=0;
    pval[0].push_back(-1);
    for(int i=0; i<n; i++) {
        sum+=arr[i]*2-1;
        pval[sum].push_back(i);
    }
    int ans=INT_MIN+50;
    for(auto i:pval) {
        vector<int> vec;
        vec=i.second;
        int mx=INT_MIN+50;
        int mn=INT_MAX-50;
        for(int j=0; j<vec.size(); j++) {
            mx=max(mx,vec[j]);
            mn=min(mn,vec[j]);
        }
        ans=max(ans,mx-mn);
    }
    
    return ans;
}
