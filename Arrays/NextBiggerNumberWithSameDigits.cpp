#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    vector<int> vec={1,2,3,4,5,6,7,8,4,9,8,7,6,5,4,3,2,1};
    n=vec.size();
    int ind=-1;

    for(int i=n-2; i>=0; i--) {
        if(vec[i]<vec[i+1]) {
            ind=i;
            break;
        }
    }

    if(ind==-1) {
        cout<<"Not Possible.";
    }

    int mn=vec[ind+1];
    int finalInd=ind+1;

    for(int i=ind+2; i<n; i++) {
        if(vec[i]>vec[ind]) {
            if(mn>vec[i]) {
                mn=vec[i];
                finalInd=i;
            }
        }
    
    }

    for(int i=finalInd; i>ind; i--) {
        swap(vec[i],vec[i-1]);
    }
    sort(vec.begin()+ind+1,vec.end());
    for(int i=0; i<n; i++) {
        cout<<vec[i];
    }
    cout<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}
