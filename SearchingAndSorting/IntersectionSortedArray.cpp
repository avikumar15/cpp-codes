// { Driver Code Starts
// C++ program to find union of 
// two sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

vector<int> printIntersection(int arr1[], int arr2[], int N, int M);  
  
/* Driver program to test above function */
int main() 
{ 
    int T;
    cin >> T;
 
    while(T--){
        
        int N, M;
        cin >> N >> M;
        int arr1[N];
        int arr2[M];
        for(int i = 0;i<N;i++){
            cin >> arr1[i];
        }
        
        for(int i = 0;i<M;i++){
            cin >> arr2[i];
        }
        
        // Function calling 
        vector<int> v;
        v = printIntersection(arr1, arr2, N, M); 
        
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";

        cout << endl;
    }
    
  return 0; 
} 
// } Driver Code Ends


/* Function prints Intersection of arr1[] and arr2[] 
N is the number of elements in arr1[] 
M is the number of elements in arr2[] 
Return the array
*/
vector<int> printIntersection(int arr1[], int arr2[], int N, int M) 
{ 
    vector<int> in;
    int a1=0,a2=0;
    int n=N,m=M;
    
    while(a1<n && a2<m) {
        if(arr1[a1]==arr2[a2]) {
            in.push_back(arr1[a1]);
            a1++;
            a2++;
        } else if(arr1[a1]>arr2[a2]) {
            a2++;
        } else {
            a1++;
        }
    }
    
    for(int i=0; i<in.size(); i++) {
        if(i==0)
            continue;
        if(in[i]==in[i-1])
            in.erase(in.begin()+i);
    }
    
    if(in.size()==0)
        in.push_back(-1);
    
    return in;
}
