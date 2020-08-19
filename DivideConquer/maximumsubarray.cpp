#include<bits/stdc++.h>
#define vi vector<int>

using namespace std;


// A utility funtion to find maximum of two integers 
int max(int a, int b) { return (a > b)? a : b; } 
  
// A utility funtion to find maximum of three integers 
int max(int a, int b, int c) { return max(max(a, b), c); } 

int maxMidIncluded(int arr[], int m, int l, int h) {
    
    int sum=arr[m];
    int right_sum=arr[m];
    int left_sum=0;

    for(int i=m+1; i<=h; i++) {
        sum+=arr[i];
        if(sum>right_sum) {
            right_sum=sum;
        }
    }
    sum=0;
    for(int i=m-1; i>=l; i--) {
        sum+=arr[i];
        if(sum>left_sum) {
            left_sum=sum;
        }
    }
    return left_sum+right_sum;
}

int maxSubArray(int arr[], int startIndex, int endIndex) {
    if(endIndex==startIndex) {
        return arr[startIndex];
    } 

    int m = (startIndex+endIndex)/2;

    cout<<"ok so now startIndex, m, endIndex - "<<startIndex<<" "<<m<<" "<<endIndex<<" "<<"\n\nmaxSubArray1- "<<maxSubArray(arr,startIndex,m)<<"\n";
    cout<<"maxSubArray2- "<<maxSubArray(arr,m+1,endIndex)<<"\n";
    cout<<"maxMidIncludedSum- "<<maxMidIncluded(arr,m,startIndex,endIndex)<<"\n\n";

    return max(maxSubArray(arr,startIndex,m), maxSubArray(arr,m+1,endIndex), maxMidIncluded(arr,m,startIndex,endIndex));
}

int main() {

    int arr[] = { -2, -5, 6, -2, -3, 1, 5, -6 };
    int N = sizeof(arr)/sizeof(arr[0]); 

    int max_sum = maxSubArray(arr,0,N-1);
    cout<<"Max continuous sum is "<<max_sum;

    return 0;
}