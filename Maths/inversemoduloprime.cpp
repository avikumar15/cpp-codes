// { Driver Code Starts
//Initial Template for C++

#include<iostream>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

int power(int a, int p, int m) {
    if(a==1) {
        return 1;
    }
    if(a==0) {
        return 0;
    }
    if(p==0) {
        return 1;
    }
    if(p==1) {
        return a%m;
    }
    
    int val = power(a,p/2,m)%m;
    
    if(p%2==1) {
        return ((((val*val)%m)*(a%m)))%m;    
    } else {
        return ((val*val)%m);
    }
    
}

int gcd(int a, int b) {
    int mx=max(a,b);
    int mn=min(a,b);
    
    if(mn==0) {
        return mx;
    }
    
    return gcd(mx%mn,mn);
}

//Complete this function
int modInverse(int a, int m)
{
    if(gcd(a,m)!=1)
        return -1;
        
    return power(a,m-2,m);
}

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--){
		int a,m;
		cin>>a>>m;
		cout << modInverse(a, m)<<endl;
	}
    return 0;
}  // } Driver Code Ends