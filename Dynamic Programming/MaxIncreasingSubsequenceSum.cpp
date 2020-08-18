using namespace std;

#include<bits/stdc++.h>

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;

        vector<int> vec;
        int temp;

        for(int i=0; i<n; i++) {
            cin>>temp;
            vec.push_back(temp);
        }

        vector<int> l(n+5,0);

        l[0]=vec[0];
        int actual=vec[0];

        for(int i=1; i<n; i++) {
            {
                int ans=0;
                for(int k=0; k<i; k++) {
                    if(vec[k]<vec[i])
                        ans=max(ans,l[k]);
                }
                l[i]=(ans+vec[i]);
                actual=max(actual,l[i]);
                
            }
        }

        // cout<<endl<<"******"<<endl;
        // for(int i=0; i<n; i++) {
        //     cout<<l[i]<<" ";
        // }
        // cout<<endl;

        cout<<actual<<endl;

    }
}
