#include<bits/stdc++.h>

using namespace std;

int j(int n, int k) {
    if(n==1)
        return 1;
    return (j(n-1,k)+k-1)%n+1;
}

int main() {
    vector<int> arr={1,2,3,4,5,6,7,8,9,10,11,12,13,14};

    int n=arr.size();
    int k=2;
    int s=2;
    cout<<j(n,k)<<" ";
    k%=n;
    k--;
    s--;

    while(arr.size()>1) {
        arr.erase(arr.begin()+(k));
        int a=arr.size();
        k=(k+s)%a;
    }

    cout<<arr[0];

}

