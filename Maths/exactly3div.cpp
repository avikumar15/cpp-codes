// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

int sieve(int n) {
    vector<bool> mark(n+5,true);
    for(int i=2; i*i<=n; i++) {
        if(mark[i]) {
            for(int s=i*i; s<=n; s+=i) {
                mark[s]=false;
            }
        }
    }
    int cnt=0;
    for(int i=2; i<=n; i++) {
        if(mark[i])
            cnt++;
    }
    return cnt;
}

//Complete this function
int exactly3Divisors(int N)
{
    int max = sqrt(N);
    int ans = sieve(max);
    return ans;
}

// { Driver Code Starts.


int main()
 {
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        cout<<exactly3Divisors(N)<<endl;
    }
	return 0;
}  // } Driver Code Ends
