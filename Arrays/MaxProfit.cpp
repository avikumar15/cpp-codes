#include<bits/stdc++.h>

using namespace std;

int main() {
    // 5 4 3 2 1 2 3 4 5
    int arr[]={5, 4, 3, 2, 1, 2, 3, 4, 5};
    int n = 9;

    // 100 180 260 310 40 535 695

    int ans=0;

    for(int i=0; i<n; i++) {
        int j=i;
        while(j+1<n && arr[j+1]>arr[j]) {
            j++;
        }  
        if(j>i)
        cout<<i<<" "<<j<<endl;
        ans+=arr[j]-arr[i];
        i=j;
    }

    cout<<ans<<endl;

    // other wise
    // 100 180 260 310 40 535 695
    ans=0;
    int val=0;
    for(int i=1; i<n; i++) {
        if(arr[i]>arr[i-1])
            continue;
        else {
            //cout<<val<<" "<<i-1<<endl;
            ans+=arr[i-1]-arr[val];
            val=i;
        }
    }
    ans+=max(0,arr[n-1]-arr[val]);

    cout<<ans<<endl;

}
