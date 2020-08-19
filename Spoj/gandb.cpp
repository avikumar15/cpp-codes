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

}

// g max, b min
float minSameGender(float b, float g) {

    float ans=g;

    for(float i=1; i<=g; i++) {
        
//        cout<<b<<" "<<(ceil(g/i)-1)<<endl;
        if(b >= ceil(g/i) -1) {
            ans=i;
            break;
        }
    }

    return ans;

}
 
int32_t main() {
   fastio;

    float ans=0;

    // for(float i=2; i<10000; i++) {
    //     ans+=1/i;
    //     cout<<ans<<" ";        
    // }

    int t=10;
//    cin>>t;
 
    while(1) {

        float g,b;
        cin>>g;
        cin>>b;

        if(g==-1 && b==-1) {
            break;
        }

        float ans=minSameGender(min(g,b),max(g,b));
        cout<<ans<<endl;

    }
    return 0;
}
