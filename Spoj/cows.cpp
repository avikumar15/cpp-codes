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

void solve() {

    int N,C;
    cin>>N>>C;

    vi vec;
    int temp;

    FORN(0,N-1) {
        cin>>temp;
        vec.push_back(temp);
    }

    sort(vec.begin(),vec.end());

    int maxx=vec[N-1];
    int minn=vec[0];
    int least=LONG_LONG_MAX;

    FORN(0,N-1) {
        if(i!=N-1) {
            least=min(least,vec[i+1]-vec[i]);
        }
    }

    int lo=least;
    int hi=maxx;
    int mid=(lo+hi)/2;

    while(hi>lo) {

        mid=(lo+hi)/2;
        int count=1;
        int temp=1;
        temp=vec[0];

        FORN(1,N-1) {
            if(vec[i]-temp>=mid) {
                count++;
                temp=vec[i];
            }
        }

    //    cout<<count<<" "<<lo<<" "<<mid<<" "<<hi<<endl;

        if(count>=C) {
            lo=mid+1;
        } else {
            hi=mid;
        }

    }

    cout<<lo-1<<endl;

}
 
int32_t main() {
    fastio;
 
    int t=10;
   cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
