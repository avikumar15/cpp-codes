#include<bits/stdc++.h>
#define int long long
#define vi vector<long long>
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAX 500 
#define FORN(start,end) for(int i=start; i<=end; i++)

using namespace std;

map<int,int> mmap;

void printVector(vi a) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,a.size()-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void printArray(int a[], int n) {
    cout<<"\n*********DEBUG**********\n";
    FORN(i,n-1) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void mergeSort(vi &vec, int l, int h, int &ans) {

    int mid=l+(h-l)/2;
    vi A,B;
    int a=0,b=0;

    // cout<<"A: ";
    for(int i=l; i<=mid; i++) {
        A.push_back(vec[i]);
        // cout<<vec[i]<<" ";
    }
    // cout<<endl<<"B: ";
    for(int i=mid+1; i<=h; i++) {
        B.push_back(vec[i]);
        // cout<<vec[i]<<" ";
    }
    // cout<<endl;
    
    int k=l;

    while(a<A.size() && b<B.size()) {
        if(A[a]<B[b]) {
            vec[k++]=A[a++];
        } else {
            vec[k++]=B[b++];
            ans+=A.size()-a;
        }
    }

    while(a<A.size()) {
        vec[k++]=A[a++];
    //    ans+=b;
    }

    while(b<B.size()) {
        vec[k++]=B[b++];
    }

    // cout<<"Ans: "<<ans<<endl;

}

void mergeS(vi &vec, int l, int h, int &ans) {

    if(l<h) {
        int mid=l+(h-l)/2;
        mergeS(vec,l,mid,ans);
        mergeS(vec,mid+1,h,ans);
        mergeSort(vec,l,h,ans);
    }

}

void solve() {

    int n;
    cin>>n;

    int temp;
    vi vec;

    FORN(0,n-1) {
        cin>>temp;
        vec.push_back(temp);
    }

    int invCount=0;
    mergeS(vec,0,n-1,invCount);

    // for(int i=0; i<n; i++) {
    //     cout<<vec[i]<<" ";
    // }
    // cout<<endl;

    cout<<invCount<<endl;

}
 
int32_t main() {
    
//    fastio;

    int t=10;
    cin>>t;
 
    while(t--) {
        solve();
    }

    return 0;
}
