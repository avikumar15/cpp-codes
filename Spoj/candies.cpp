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
 
int32_t main() {
    fastio;
 
    int t=10;
    cin>>t;
    
    while(t--) {
        int count=0;
        int n;
        cin>>n;
        int sum=0;
        int temp;

        FORN(0,n-1) {
            cin>>temp;
            sum+=temp%n;
            sum%=n;
        }

        if(sum%n==0) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }

    }
    return 0;
}
