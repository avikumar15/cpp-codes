// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

long long getSmallestDivNum(long long n);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<getSmallestDivNum(n)<<endl;
	}
	return 0;
	
}// } Driver Code Ends

long long LCM(long long i, long long l) {
    long long g=__gcd(i,l);
    return (i/g)*l;
}

/*You are required to complete this method */
long long getSmallestDivNum(long long n)
{
    //Your code here
    long long l=1;
    
    // lcm of 1 to n.
    for(long long i=2; i<=n; i++) {
        l=LCM(i,l);    
    }
    
    return l;
    
}
