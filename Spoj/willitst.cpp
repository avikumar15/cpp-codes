#include<bits/stdc++.h>
#define int unsigned long long
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

void solve() {

}
 
int32_t main() {
//   fastio;

    float ans=0;

    // for(float i=2; i<10000; i++) {
    //     ans+=1/i;
    //     cout<<ans<<" ";        
    // }

    int t=10;
//    cin>>t;
 
    while(1) {

        int n;
        cin>>n;
        set <int> sset;
        int fu=0;

        while(n>1) {

            sset.insert(n);

            if(n%2==0) {
                n=n/2;
            }
            else {
                n=3*n+3;
            }

            if(sset.count(n)>=1) {
                fu=-1;
                break;
            }

        }

        if(fu==-1) {
            cout<<"NIE\n";
        } else {
            cout<<"TAK\n";
        }
        break;

    }

    return 0;
}
