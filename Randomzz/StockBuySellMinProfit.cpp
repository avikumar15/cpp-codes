#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    int arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    while(d--) {

        int reqd;
        cin >> reqd;

        int ans = 0;
        int mn = arr[0];
        int mnPos = 1;
        int mxPos = 1;

        for(int i=1; i<n; i++) {
            ans = max(ans,arr[i]-mn);
            if(ans >= reqd) {
                mxPos = i+1;
                break;
            }
            if(mn >= arr[i]) {
                mn = min(mn,arr[i]);
                mnPos = i+1;
            }
        }

        cout<<mnPos<<" "<<mxPos;
        
        if(d != 0)
            cout<<", ";
    }

}
