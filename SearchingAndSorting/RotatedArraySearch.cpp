// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int K) {
    //code here
    int p=0;
    int n=vec.size();
    int k=K;
    int l=0;
    int h=n-1;
    int m=l+(h-l)/2;
    
    if(n==0) {
        return -1;
    }
    /**
     * 5 1 2 3 4
     * 5
     * p is 4
     * -1
    */

    while(h>l) {
        
        m=l+(h-l)/2;

        if(m==n-1) {
            p=n-1;
            break;
        }
        
        if(vec[m]>vec[m+1]) {
            p=m;
            break;
        }

        if(vec[l]>vec[l+1]) {
            p=l;
            break;
        }

        if(h!=n-1) {
            if(vec[h]>vec[h+1]) {
                p=h;
                break;
            }
        }

        // cout<<vec[m]<<"-"<<vec[h]<<" ";

        if(vec[m]>=vec[h]) {
            l=m+1;
        } else {
            h=m-1;
        }
        
    }

    // cout<<"p is "<<p<<endl;
    
    l=0;
    h=p;
    
    while(h>l) {
        m=l+(h-l)/2;
        if(vec[m]==K) {
            l=m;
            break;
        }
        if(vec[m]>=K) {
            h=m;
        } else {
            l=m+1;
        }
    }
    
    if(vec[l]==K) {
        return l;
    }
    
    l=p+1;
    h=n-1;
    
    while(h>l) {
        m=l+(h-l)/2;
        if(vec[m]==K) {
            l=m;
            break;
        }
        if(vec[m]>=K) {
            h=m;
        } else {
            l=m+1;
        }
    }

    if(vec[l]==K) {
        return l;
    } else {
        return -1;
    }
    
}
