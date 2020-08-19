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

    float ans=0;

    int t=10;
 
    int n;
    cin>>n;

    vi vec;
    int temp;

    FORN(0,n-1) {
        cin>>temp;
        vec.push_back(temp);
    }

    int m;
    cin>>m;

    while(m--) {

        int x,y;
        cin>>x>>y;

        

    }
    return 0;
}
