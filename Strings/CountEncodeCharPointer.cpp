// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

char *encode(char *src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		char str[10000];
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */
#include<bits/stdc++.h>
char *encode(char *src)
{     
    int n=strlen(src);
    char *ans = new char[3*n];
    int ind=1;
    *ans=*src;
    char last=*src;
    int cnt=1;
    
    for(int i=1; i<n; i++) {
        if(*(src+i)==*(src+i-1)) {
            cnt++;
        } else {
            *(ans+ind++)=(cnt)+'0';
            *(ans+ind++)=src[i];
            cnt=1;
        }
    }
    *(ans+ind++)=(cnt)+'0';
    return ans;
}     
