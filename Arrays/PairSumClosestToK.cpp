#include<bits/stdc++.h>

using namespace std;

int main() {
    int arr[]={27, 1,10, 39, 12, 52, 32, 67, 76};
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int k=77;

    int p1=0;
    int p2=n-1;
    int minvalue=INT_MAX-10;

    while(p2>p1) {
        if(arr[p2]+arr[p1]<=k) {
            minvalue=min(minvalue,k-arr[p1]-arr[p2]);
            p1++;
        } else {
            p2--;
        }
    }

}
