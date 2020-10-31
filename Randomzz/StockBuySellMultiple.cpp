#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int ans = 0;

    for(int i=0; i<n; i++) {
        
        int j = i;

        while(j+1<n && arr[j+1]>arr[j]) 
            j++;

        ans += arr[j]-arr[i];
        i = j;
    }

    cout<<ans<<"\n";

}
