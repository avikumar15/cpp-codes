#include<bits/stdc++.h>

using namespace std;

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

        vector<int> l;
        int ans[n];
        
        // {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15}
        // 0 2 12 
        for(int i=0; i<n; i++) {
            auto lb = lower_bound(l.begin(),l.end(),vec[i]);
            int ind = lb-l.begin();
            if(lb==l.end()) {
                l.push_back(vec[i]);
            } else {
                l[ind]=vec[i];
            }
            for(int i=0; i<l.size(); i++) {
                cout<<l[i]<<" ";
            }
            cout<<endl;
            ans[i]=ind+1;
        }
    
        cout<<l.size()<<endl;

    }
}
