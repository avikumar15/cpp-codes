#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    int ans = 0;
    int mn = arr[0];

    for(int i=1; i<n; i++) {
        ans = max(ans,arr[i]-mn);
        mn = min(mn,arr[i]);
    }

    cout<<ans<<"\n";

}
