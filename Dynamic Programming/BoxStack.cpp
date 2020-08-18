// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int maxHeight(int height[],int width[],int length[],int n);

int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	

 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} // } Driver Code Ends

struct Box {
    int h,w,l;
};

bool comp (Box a, Box b) {
    return (a.w*a.l > b.w*b.l);
}

/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/

int maxHeight(int ht[],int wt[],int lt[],int n)
{
    // h 4 6 7 1 
    // w 2 3 4 5 
    // l 6 10 12 32
    
    int ind=0;
    Box boxes[3*n];
    
    for(int i=0; i<n; i++) {
        boxes[ind].h=ht[i];
        boxes[ind].w=max(wt[i],lt[i]);
        boxes[ind].l=min(wt[i],lt[i]);
        
        ind++;
        
        boxes[ind].h=wt[i];
        boxes[ind].w=max(ht[i],lt[i]);
        boxes[ind].l=min(ht[i],lt[i]);
        
        ind++;
        
        boxes[ind].h=lt[i];
        boxes[ind].w=max(ht[i],wt[i]);
        boxes[ind].l=min(ht[i],wt[i]);
        
        ind++;
        
    }
    
    n=3*n;
    sort(boxes,boxes+n,comp);
    
    int ans[n];
    
    for(int i=0; i<n; i++) {
        ans[i]=boxes[i].h;       
    }
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(boxes[i].w<boxes[j].w && boxes[i].l<boxes[j].l) {
                ans[i]=max(ans[i],boxes[i].h+ans[j]);
            }
        }
    }
    
    int mx=0;
    
    for(int i=0; i<n; i++) {
        mx=max(mx,ans[i]);
    }
    
    return mx;
    
}
