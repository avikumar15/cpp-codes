#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>

using namespace std;

int32_t main() {
    
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
        int temp;
        vi vec;

        for(int i=0; i<n; i++) {
            cin>>temp;
            vec.push_back(temp);
        }

        // [-3, 4, -1, -2, 1, 5]

        int sum=0;
        int ans=LONG_LONG_MIN;

        for(int i=0; i<n; i++) {

            sum+=vec[i];
            ans=max(ans,sum);
            sum=max(sum,(int)0);

        }

        cout<<ans<<endl;
    }

}
