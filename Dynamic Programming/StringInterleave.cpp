// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}// } Driver Code Ends


bool isInterleave(string A, string B, string C, map<string,bool>& mmap) {
    if(A.size()==0 && B.size()==0 && C.size()==0)
        return true;
    if(C.size()==0)
        return false;
    if(mmap.find(A+"|"+B+"|"+C)!=mmap.end())
        return mmap[A+B+C];
    
    bool f = A[0]==C[0] && !A.size()==0 && isInterleave(A.substr(1),B,C.substr(1),mmap);
    bool s = B[0]==C[0] && !B.size()==0 && isInterleave(A,B.substr(1),C.substr(1),mmap);
    
    mmap[A+"|"+B+"|"+C]=f||s;
    return f||s;
}

/*You are required to complete this method */
bool isInterleave(string A, string B, string C) 
{
    map<string,bool> mmap;
    return isInterleave(A,B,C,mmap);
    
}
