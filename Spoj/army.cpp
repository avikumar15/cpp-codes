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

int caseNo=1;

void solve() {

    int ng,nm;

    cin>>ng>>nm;
    int max1=INT_MIN,max2=INT_MIN;
    int temp;

    for(int i=0; i<ng; i++) {
        cin>>temp;
        max1=max(max1,temp);
    }

    for(int i=0; i<nm; i++) {
        cin>>temp;
        max2=max(max2,temp);
    }

    if(max1>=max2) {
        cout<<"Godzilla\n";
    } else {
        cout<<"MechaGodzilla\n";
    }

}
 
int32_t main() {
    
    fastio;

    int t=1;
    cin>>t;
 
    while(t--) {
        solve();
    }

    return 0;
}
