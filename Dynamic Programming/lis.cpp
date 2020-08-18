#include<bits/stdc++.h>

using namespace std;

// alternate
int lisnlogn(int a[], int n) {
    
    // a is
    // [1 3 6 4 5 12]

    int l[n];
    vector<int> I;

    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(I.begin(), I.end(), a[i]);
        int index = it - I.begin();
        if (it == I.end())
            I.push_back(a[i]);
        else
        {
            I[index] = a[i];
        }
        l[i] = index + 1;
    }
    return I.size();
}

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

        l[0]=1;
        int actual=1;

        for(int i=1; i<n; i++) {
            {
                int ans=0;
                for(int k=0; k<i; k++) {
                    if(vec[k]<vec[i])
                        ans=max(ans,l[k]);
                }
                l[i]=(ans+1);
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
